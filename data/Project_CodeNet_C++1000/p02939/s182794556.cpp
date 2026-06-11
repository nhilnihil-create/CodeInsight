#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9 + 7, A = 1e5 + 2;

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    cin >> s;
    string t;
    int cnt = 0;
    map<string, bool> mop;
    for (int i = 0; i < (int)s.size(); i++) {
        t.pb(s[i]);
        if (mop[t] == 0) {
            mop.clear();
            mop[t] = 1, cnt++;
            t.clear();
        }
    }
    cout << cnt;
    return 0;
}
