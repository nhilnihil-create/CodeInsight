#include <bits/stdc++.h>

using namespace std;

int main() {
    string S, T;
    int cnt = 0;
    vector<string> tenki;
    vector<string> yosou;

    cin >> S;
    cin >> T;

    for (int i = 0; i < 3; ++i) {
        char C1, C2;
        C1 = S[i];
        C2 = T[i];
        if (C1 == C2)cnt++;
    }

    cout << cnt << endl;
}