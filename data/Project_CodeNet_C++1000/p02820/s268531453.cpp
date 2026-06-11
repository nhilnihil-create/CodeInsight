# include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    map<char,int> mp;
    int r, s, p; cin >> r >> s >> p;
    mp['r'] = p; mp['s'] = r; mp['p'] = s;
    string t; cin >> t;
    int ans = 0;
    rep(i,k) {
        char now = t[i];
        int len = 0;
        for (int j = i; j < n; j += k) {
            if (t[j] == now) len++;
            else {
                ans += (len+1)/2 * mp[now];
                len = 1;
                now = t[j];
            }
        }
        ans += (len+1)/2 * mp[now];
    }  
    cout << ans << endl;
}