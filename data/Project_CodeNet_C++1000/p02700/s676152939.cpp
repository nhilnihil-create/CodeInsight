#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e5 +7;

#include <math.h>
#define PI 3.14159265358979323846264338327950L



int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    bool turn = true;
    while (A > 0 && C > 0) {
        if (turn) {
            C -= B;
        }
        else {
            A -= D;
        }
        turn ^= 1;
    }
    if (A <= 0) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }

    return 0;
}