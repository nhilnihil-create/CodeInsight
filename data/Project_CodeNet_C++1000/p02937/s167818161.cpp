#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)

int main() {
    string s, t; cin >> s >> t;
    ll n = s.size();
    s+=s;
    vector<vector<ll>> sd(26);
    rep(i, s.size()) sd[s[i]-'a'].push_back(i);
    if (sd[t[0]-'a'].size() == 0) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = sd[t[0]-'a'][0]+1;
    ll tmp = sd[t[0]-'a'][0];
    rep(i, t.size()-1) {
        if (sd[t[i+1]-'a'].size() == 0) {
            cout << -1 << endl;
            return 0;
        }
        ans += sd[t[i+1]-'a'][upper_bound(ALL(sd[t[i+1]-'a']), tmp) - sd[t[i+1]-'a'].begin()] - tmp;
        tmp = (sd[t[i+1]-'a'][upper_bound(ALL(sd[t[i+1]-'a']), tmp) - sd[t[i+1]-'a'].begin()])%n;
    }
    cout << ans << endl;
}
