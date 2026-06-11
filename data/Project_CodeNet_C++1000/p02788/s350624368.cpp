#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

vector<ll> x;
vector<ll> h;
vector<P> pairs;

int main(){
    int n;
    ll d, a;
    cin >> n >> d >> a;
    rep(i, n){
        ll p, q;
        cin >> p >> q;
        pairs.push_back(make_pair(p, q));
    }
    sort(pairs.begin(), pairs.end());
    rep(i, n){
        x.push_back(pairs[i].first);
        h.push_back(pairs[i].second);
    }


    int nxt[200010];
    rep(i, n){
        auto itr = upper_bound(x.begin(), x.end(), x[i] + 2 * d);
        // cout << itr - x.begin() << endl;
        nxt[i] = itr - x.begin();
    }
    ll cnt = 0;
    vector<ll> s(n + 1, 0);
    rep(i, n){
        if (s[i] < h[i]){
            ll diff = ((h[i] - s[i] + a - 1) / a);
            s[i] += diff * a;
            s[nxt[i]] -= diff * a;
            cnt += diff;
        }
        s[i+1] += s[i];
    }

    cout << cnt << endl;

    return 0;
}