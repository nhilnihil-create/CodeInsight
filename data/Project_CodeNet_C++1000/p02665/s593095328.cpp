#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

int N;
ll A[100010];
ll acc[100010], num[100010];

signed main(){
    cin >> N;
    REP(i, N + 1) cin >> A[i];
    REP(i, N + 1){
        acc[i] += A[i];
        acc[i + 1] += acc[i];
    }
    if(A[0] > 1){
        PRINT("-1");
        return 0;
    }
    num[0] = 1;
    ll ans = 1;
    FOR(i, 1, N + 1){
        num[i] = min((num[i - 1] - A[i - 1]) * 2, acc[N] - acc[i - 1]);
        if(num[i] <= 0){
            PRINT("-1");
            return 0;
        }
        ans += num[i];
    }
    if(num[N] != A[N]){
        PRINT("-1");
        return 0;
    }
    PRINT(ans);
    return 0;
}