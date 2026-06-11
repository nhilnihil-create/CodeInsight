#include<bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
    string s;
    cin >> s;
    int n = (int) s.size();
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            if (s[i] != 'L' && s[i] != 'U' && s[i] != 'D') {
                cout << "No";
                return;
            }
        } else {
            if (s[i] != 'R' && s[i] != 'U' && s[i] != 'D') {
                cout << "No";
                return;
            }
        }
    }
    cout << "Yes";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}
