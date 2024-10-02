#include <iostream>
#include <string>
using namespace std;

class MovieTheatre {
private:
    char seats[10][10];  // 2D array for seating chart
    int rows, cols;
    string movies[5] = {"Inception", "Avatar", "Interstellar", "Titanic", "The Dark Knight"};  // Available movies
    int movieCount = 5;

public:
    // Constructor to initialize the seating chart
    MovieTheatre(int r, int c) : rows(r), cols(c) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                seats[i][j] = 'O';  // 'O' indicates an available seat
            }
        }
    }

    // Display the seating chart
    void displaySeats() {
        cout << "Seating Chart (O: Available, X: Reserved)" << endl;
        cout << "  ";
        for (int i = 0; i < cols; i++) {
            cout << i + 1 << " ";  // Display column numbers
        }
        cout << endl;

        for (int i = 0; i < rows; i++) {
            cout << i + 1 << " ";  // Display row numbers
            for (int j = 0; j < cols; j++) {
                cout << seats[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Reserve a seat
    void reserveSeat(int row, int col) {
        if (row < 1 || row > rows || col < 1 || col > cols) {
            cout << "Invalid seat selection. Please try again." << endl;
        } else if (seats[row - 1][col - 1] == 'X') {
            cout << "Seat already reserved. Please choose another seat." << endl;
        } else {
            seats[row - 1][col - 1] = 'X';  // Mark seat as reserved
            cout << "Seat reserved successfully!" << endl;
        }
    }

    // Unreserve (delete) a seat
    void deleteSeat(int row, int col) {
        if (row < 1 || row > rows || col < 1 || col > cols) {
            cout << "Invalid seat selection. Please try again." << endl;
        } else if (seats[row - 1][col - 1] == 'O') {
            cout << "Seat is already available. No reservation found." << endl;
        } else {
            seats[row - 1][col - 1] = 'O';  // Mark seat as available again
            cout << "Seat unreserved successfully!" << endl;
        }
    }
    void movieList(){
        cout<<"Choose the following today's available movies "<<endl;
        cout<<"Inception"<<endl;
        cout<<"Avtar"<<endl;
        cout<<"Interstellar"<<endl;
        cout<<"Titanic"<<endl;
        cout<<"The Dark Knight"<<endl;
    }

    // Function to check if a movie is available
    void checkMovieAvailability(string movieName) {
        
        bool found = false;
        for (int i = 0; i < movieCount; i++) {
            if (movies[i] == movieName) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "The movie '" << movieName << "' is available!" << endl;
        } else {
            cout << "Sorry, the movie '" << movieName << "' is not available." << endl;
        }
    }
};

int main() {
    int rows = 5, cols = 5;  // Define size of the seating chart
    MovieTheatre theatre(rows, cols);
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Check movie availability" << endl;
        cout << "2. Reserve a seat" << endl;
        cout << "3. Unreserve a seat" << endl;
        cout << "4. Display seating chart" << endl;
        cout<<  "5.Enter movie List"<<endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string movieName;
            cout << "Enter the movie name: ";
            cin.ignore();  // To ignore the newline character left by previous input
            getline(cin, movieName);  // Get movie name from user
            theatre.checkMovieAvailability(movieName);  // Check if the movie is available
        } else if (choice == 2) {
            int row, col;
            cout << "Enter row number: ";
            cin >> row;
            cout << "Enter column number: ";
            cin >> col;
            theatre.reserveSeat(row, col);  // Reserve a seat
        } else if (choice == 3) {
            int row, col;
            cout << "Enter row number: ";
            cin >> row;
            cout << "Enter column number: ";
            cin >> col;
            theatre.deleteSeat(row, col);  // Unreserve a seat
        } else if (choice == 4) {
            theatre.displaySeats();  // Display the seating chart
        }
        else if (choice ==5){
            theatre.movieList();
        }
    } while (choice != 6);

    cout << "Thank you for using the movie and seat reservation system!" << endl;
    return 0;
}
