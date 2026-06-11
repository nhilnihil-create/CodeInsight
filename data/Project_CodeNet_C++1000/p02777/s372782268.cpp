#include "bits/stdc++.h"

using namespace std;

void Main() {
    string S, T, U;
    int A, B;
    cin >> S >> T;
    cin >> A >> B;
    cin >> U;

    if (U == S) {
        cout << (A - 1) << " " << B << endl;
    }
    else {
        cout << A << " " << (B - 1) << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
