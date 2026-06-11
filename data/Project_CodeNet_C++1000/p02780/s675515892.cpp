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

int K, N;
double p[200010];
double E[200010];
double acc[200010];

signed main(){
    cin >> N >> K;
    REP(i, N){
        cin >> p[i];
        p[i] = (1 + p[i]) / 2;
    }
    double ans = 0, sum = 0;
    REP(i, K) sum += p[i];
    ans = sum;
    REP(i, N - K){
        sum = sum - p[i] + p[i + K];
        ans = max(ans, sum);
    }
    printf("%.9Lf\n", ans);
    return 0;
}