#include <bits/stdc++.h>
using namespace std;




























int main () {
    long long N;
    cin >> N;
    vector<long long> vect;
    while (N > 0) {
        vect.push_back(N % 26);
        if (N % 26 == 0) N -= 26;
        N /= 26;
    }

    reverse (vect.begin(), vect.end());

    for (long long i: vect) {
        if (i == 1) {
            cout << "a";
        }
        if (i == 2) {
            cout << "b";
        }
        if (i == 3) {
            cout << "c";
        }
        if (i == 4) {
            cout << "d";
        }
        if (i == 5) {
            cout << "e";
        }
        if (i == 6) {
            cout << "f";
        }
        if (i == 7) {
            cout << "g";
        }
        if (i == 8) {
            cout << "h";
        }
        if (i == 9) {
            cout << "i";
        }
        if (i == 10) {cout << "j";}
        if (i == 11) {cout << "k";}
        if (i == 12) {cout << "l";}
        if (i == 13) cout << "m";
        if (i == 14) cout << "n";
        if (i == 15) cout << "o";
        if (i == 16) cout << "p";
        if (i == 17) cout << "q";
        if (i == 18) cout << "r";
        if (i == 19) cout << "s";
        if (i == 20) cout << "t";
        if (i == 21) cout << "u";
        if (i == 22) cout << "v";
        if (i == 23) cout << "w";
        if (i == 24) cout << "x";
        if (i == 25) cout << "y";
        if (i == 0) cout << "z";
    }

    cout << endl;
}