#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define m0(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); i++)
#define asort(x) sort(all(x));
#define dsort(x, t) sort(x.begin(), x.end(), greater<t>());
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define MINS(m, s) m.insert(make_pair(s, 1));
#define MFIN(m, s) m.find(s) != m.end()
#define INF (1 << 29)
const int mod = 1000000007;

int main() {
    ll n, m, p, ac, wa;
    string s;
    ll cnt_ac[100005], cnt_wa[100005];
    m0(cnt_ac);
    m0(cnt_wa);
    cin >> n >> m;

    for(ll i = 0; i < m; i++) {
        cin >> p >> s;
        if(s == "AC") {
            cnt_ac[p] = 1;
        } else {
            if(cnt_ac[p] == 0) {
                cnt_wa[p]++;
            }
        }
    }

    ac = 0, wa = 0;
    for(ll i = 1; i <= n; i++) {
        if(cnt_ac[i] == 1) {
            ac++;
            wa += cnt_wa[i];
        }
    }

    cout << ac << " " << wa << endl;
    return 0;
}