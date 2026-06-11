#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string s, r, s1 = "", s2 = "";
    cin >> s;
    r = s;
    reverse(r.begin(), r.end());
    rep(i, s.size()) {
        if(s[i] != r[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    for(int i = 0; i < (s.size() - 1) / 2; i++) {
        s1 += s[i];
    }
    for(int i = (s.size() + 1) / 2; i < s.size(); i++) {
        s2 += s[i];
    }
    r = s1;
    reverse(r.begin(), r.end());
    rep(i, s1.size()) {
        if(s1[i] != r[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    r = s2;
    reverse(r.begin(), r.end());
    rep(i, s2.size()) {
        if(s2[i] != r[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}