#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int main(){
    string s;
    string t;
    cin >> s >> t;
    vector<ll> alph[26];
    rep(i, s.size()) alph[s[i]-'a'].push_back(i);

    ll idx = -1; // s中のどの文字を使ったか
    ll d = 0; // 繰り返し数
    rep(i, t.size()){
        char c = t[i];
        if (alph[c-'a'].size() == 0) {
            cout << -1 << endl;
            return 0;
        }
        else if (idx >= alph[c-'a'].back()){
            idx = alph[c-'a'][0];
            d++;
        }
        else {
            ll nxt = *upper_bound(alph[c-'a'].begin(), alph[c-'a'].end(), idx);
            idx = nxt;
        }
        // cout << idx << " " << d << endl;
    }

    cout << ll(s.size()) * d + idx + 1 << endl;

    return 0;
}
