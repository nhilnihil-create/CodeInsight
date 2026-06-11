#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    bool ans = false;
    if (S[0] == S[1] && S[2] == S[3]) ans = true;
    if (S[0] == S[2] && S[1] == S[3]) ans = true;
    if (S[0] == S[3] && S[1] == S[2]) ans = true;
    if (S[0] == S[1] && S[1] == S[2] && S[2] == S[3]) ans = false;
    cout << (ans ? "Yes" : "No") << endl;
}