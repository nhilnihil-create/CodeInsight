
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void Main() {
    // input
    string S, T;
    int A, B;
    string U;

    cin >> S >> T;
    cin >> A >> B;
    cin >> U;

    // process
    if (U ==S) {
        A--;
    } else if (U == T) {
        B--;
    } else {
        cout << "Error";
    }


    // output
    cout << A << " " << B << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
