#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

ll N, K;
ll A[200010], acc[200010];
map<ll, ll> mp;

signed main(){
    cin >> N >> K;
    REP(i, N) cin >> A[i];
    ll ans = 0;
    acc[0] = (A[0] - 1) % K;
    REP(i, N - 1){
        acc[i + 1] = (acc[i] + A[i + 1] - 1) % K;
    }
    REP(i, min(N, K - 1)) mp[acc[i]]++;
    ans += mp[0];
    mp[acc[0]]--;
    int j = K - 2;
    FOR(i, 1, N){
        if(j < N - 1){
            j++;
            mp[acc[j]]++;
        }
        if(i <= j) ans += mp[acc[i - 1]];
        mp[acc[i]]--;
    }
    PRINT(ans);
    return 0;
}