#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    string S;
    cin >> S;

    int cnt = 0;
    bool w = true;
    rep (i, 3) {
        if (w) {
            if (S[i] == (char)'R') {
                cnt++;
            } else {
                continue;
            }
            w = false;
        }
        if ((S[i] == (char)'R') && (S[i+1] == (char)'R')) {
            cnt++;
            } else {
                continue;
            }
    }

    cout << cnt << endl;

    return 0;
}