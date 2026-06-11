#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    cin >> S;

    char c1 = S[2], c2 = S[3], c3 = S[4], c4 = S[5];
    if (c1 == c2 && c3 == c4) {
        cout << "Yes" << endl;
        return 0;
    } else {
        cout << "No" << endl;
        return 0;
    }

}