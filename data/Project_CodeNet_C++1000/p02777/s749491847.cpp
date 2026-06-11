//
// Created by David Sarpong on 5/30/20.
//

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    string S, T;
    int A, B;

    cin >> S >> T >> A >> B;

    string U;
    cin >> U;

    if (U == S) {
        A--;
    }
    else {
        B--;
    }

    cout << A << " " << B << "\n";

    return 0;
}