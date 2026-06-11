#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

ll N;
map<ll, ll> mp;
ll pow2[61];

signed main(){
    cin >> N;
    unsigned long long a;
    REP(i, N){
        cin >> a;
        REP(j, 61){
            if(a == 0) continue;
            if(a % 2 == 1) mp[j]++;
            a /= 2;
        }
    }
    pow2[0] = 1;
    REP(i, 60) pow2[i + 1] = (pow2[i] * 2) % MOD;
    ll ans = 0;
    REP(i, 61){
        ll k = mp[i] * (N - mp[i]) % MOD;
        ans = (ans + k * pow2[i] % MOD) % MOD;
    }
    PRINT(ans);
    return 0;
}