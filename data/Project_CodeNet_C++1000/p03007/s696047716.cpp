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

ll x[100010];
ll y[100010];

vector<ll> pos, neg;

int main(){
    int n;
    cin >> n;
    rep(i, n){
        ll a;
        cin >> a;
        if (a >= 0) pos.push_back(a);
        else neg.push_back(a);
    }
    sort(pos.rbegin(), pos.rend());
    sort(neg.begin(), neg.end());

    if (neg.empty()) neg.push_back(pos.back()), pos.pop_back();
    if (pos.empty()) pos.push_back(neg.back()), neg.pop_back();

    vector<P> res;
    ll now = neg[0];
    for (int i = 0; i+1 < pos.size(); ++i) {
        res.push_back({now, pos[i]});
        now -= pos[i];
    }
    res.push_back({pos.back(), now});
    now = pos.back() - now;

    for (int i = 1; i < neg.size(); ++i) {
        res.push_back({now, neg[i]});
        now -= neg[i];
    }

    cout << now << endl;
    rep(i, n-1) cout << res[i].first << " " << res[i].second << endl;

    return 0;
}
