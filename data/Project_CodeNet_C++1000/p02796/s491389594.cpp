#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef pair<ll, ll> P;
#define INF (1LL << 31)
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define PRINT(V) for (auto v : (V)) cout << v << " "

int main()
{
    ll n, x, l; cin >> n;
    vector<P> arm(n);
    rep(i, n) {
        cin >> x >> l;
        arm[i].first = x + l;
        arm[i].second = x - l;
    }

    sort(arm.begin(), arm.end());
    ll ra = -INF;
    ll cnt = 0;

    rep(i, n) {
        if (ra <= arm[i].second){
            ++cnt;
            ra = arm[i].first;
        }
    };
    // rep(i, n) cout << arm[i].first << " " << arm[i].second << endl;
    cout << cnt << endl;
    return 0;
}
