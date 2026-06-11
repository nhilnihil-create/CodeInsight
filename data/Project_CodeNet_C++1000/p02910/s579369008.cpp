#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    rep(i, s.size()) {
        if((i + 1) % 2 == 0) {
            if(s[i] == 'R') {
                cout << "No" << endl;
                return 0;
            }
        } else {
            if(s[i] == 'L') {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}