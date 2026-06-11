//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    string s, t;
    cin >> s >> t;
    int ns = s.size();
    int nt = t.size();
    vvi q(26);
    rep(i, ns) {
        q[s[i]-'a'].push_back(i);
    }

    ll ans = 0LL;
    int now = -1;
    vi noww(26);
    rep(i, nt) {
        while(noww[t[i] - 'a'] != q[t[i] - 'a'].size() && q[t[i] - 'a'][noww[t[i] - 'a']] < now) {
            noww[t[i] - 'a']++;
        }
        if(noww[t[i] - 'a'] == q[t[i] - 'a'].size()) {
            if(q[t[i] - 'a'].empty()) {
                cout << -1 << endl;
                return 0;
            } else {
                ans += ns;
                noww.assign(26, 0);
            }
        }
        int nn = q[t[i] - 'a'][noww[t[i] - 'a']];
        //cout << nn << endl;
        noww[t[i] - 'a']++;
        //cout << ans << endl;
        ans += nn-now;
        //cout << ans << endl;
        now = nn;
    }

    cout << ans << endl;
}