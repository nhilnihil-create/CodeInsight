#include <bits/stdc++.h>

using namespace std;

int main() {

    string S;
    cin >> S;

    for (int i = 0; i < S.length(); ++i) {
        char C1, C2;
        C1 = S[i];
        C2 = S[i + 1];
        if (C1 == C2) {
            cout << "Bad" << endl;
            return 0;
        }
    }

    cout << "Good" << endl;

}