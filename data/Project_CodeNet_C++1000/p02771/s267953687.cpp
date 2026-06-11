
#include <iostream>
#include <iomanip>
using namespace std;

void Main() {
    // input
    int A, B, C;
    cin >> A >> B >> C;


    // translate
    int count = 0;
    if (A == B) {
        count++;
    }
    if (B == C) {
        count++;
    }
    if (C == A) {
        count++;
    }

    // output
    if (count == 1) {
        cout << "Yes";
    } else {
        cout << "No";
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
