#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 998244353

typedef long long ll;
typedef pair<ll,ll> P;

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

    ll k, q;cin >> k >> q;
    vector<ll> v(k);REP(i, k)cin >> v[i];

    REP(s_e_i_c_a, q){
        ll n, x, m;cin >> n >> x >> m;n--;
        ll sum = x % m;
        REP(i, min(k, n)){
            ll now = v[i] % m;
            sum += now * ((n / k) + (i < (n % k)));
        }
        ll ans = n - (sum / m);
        REP(i, min(k, n)){
            if(v[i] % m != 0)continue;
            //cout << "! " << v[i] << endl;
            ans -= ((n / k) + (i < (n % k)));
        }
        cout << ans << endl;
    }

	return 0;
}
