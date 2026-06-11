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


ll a[510];

// 約数列挙
vector<ll> divisor(ll n) {
    vector<ll> ret;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
            }
    }
    sort(begin(ret), end(ret));
    sort(ret.begin(), ret.end(), greater<ll>());
    return (ret);
}

int main(){
    ll n, k;
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    ll s = 0;
    rep(i, n) s += a[i];

    vector<ll> div = divisor(s);

    rep(j, div.size()){
        ll d = div[j];
        ll cost = 0;
        vector<ll> b;
        rep(i, n) b.push_back(a[i] % d);
        sort(b.begin(), b.end());
        vector<ll> l(n+1), r(n+1);
        l[0] = 0, r[n] = 0;
        rep(i, n) l[i+1] += l[i] + b[i];
        rrep(i, n) r[i] += (d - b[i]) + r[i+1];
        rep(i, n+1) if (l[i] == r[i] && l[i] <= k){
            cout << d << endl;
            return 0;
        }
    }


    return 0;
}
