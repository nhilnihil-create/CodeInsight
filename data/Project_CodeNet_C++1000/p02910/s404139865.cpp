#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    bool ans = true;
    for (int i = 0; i < (int)S.size(); i++) {
        if (i % 2 == 1 && S[i] == 'R') ans = false;
        else if (i % 2 == 0 && S[i] == 'L') ans = false;
    }
    cout << (ans ? "Yes" : "No") << endl;
}