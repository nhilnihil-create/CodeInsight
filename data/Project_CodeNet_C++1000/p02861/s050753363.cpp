#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

#define double long double

int N;
double x[10], y[10];
double ans;

void dfs(double dist, int n, int state){
    if(state == (1 << N) - 1){
        ans += dist;
        return;
    }
    REP(i, N){
        if(state & (1 << i)) continue;
        dfs(dist + sqrtf64x((x[n] - x[i]) * (x[n] - x[i]) + (y[n] - y[i]) * (y[n] - y[i])), i, state | (1 << i));
    }
}

int fact(int n){
    if(n == 0) return 1;
    return n * fact(n - 1);
}

signed main(){
    cin >> N;
    REP(i, N) cin >> x[i] >> y[i];
    REP(i, N) dfs(0, i, 1 << i);
    printf("%.9Lf\n", ans / fact(N));
    return 0;
}