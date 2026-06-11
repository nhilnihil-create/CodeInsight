#include <bits/stdc++.h>

using namespace std;

int main() {
    string S, T;
    bool fg = true;
    cin >> S;
    cin >> T;

    if (S.size() + 1 == T.size()) {
        for (int i = 0; i < S.size(); i++) {
            if (S.at(i) != T.at(i)) {
                cout << "No" << endl;
                fg = false;
                break;
            }
        }
    } else {
        cout << "No" << endl;
        fg = false;
    }

    if (fg)cout << "Yes" << endl;

}