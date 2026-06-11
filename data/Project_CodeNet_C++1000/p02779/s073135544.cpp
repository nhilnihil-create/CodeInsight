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

signed main(){
    cin >> N;
    ll a;
    bool ok = true;
    REP(i, N){
        cin >> a;
        mp[a]++;
        if(mp[a] > 1) ok = false;
    }
    if(ok) PRINT("YES");
    else PRINT("NO");
    return 0;
}