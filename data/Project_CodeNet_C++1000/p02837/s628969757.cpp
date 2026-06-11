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
int A[20];
int x[20][20], y[20][20];
int p[20];

int check(int state){
    REP(i, N){
        if(state & (1 << i)) p[i] = 1;
        else p[i] = 0;
    }
    REP(i, N){
        REP(j, A[i]){
            if(p[i] == 0) continue;
            if(p[x[i][j]] != y[i][j]) return -1;
        }
    }
    return __builtin_popcount(state);
}

signed main(){
    cin >> N;
    REP(i, N){
        cin >> A[i];
        REP(j, A[i]){
            cin >> x[i][j] >> y[i][j];
            x[i][j]--;
        }
    }
    int ans = 0;
    REP(i, 1 << N) ans = max(ans, check(i));
    PRINT(ans);
    return 0;
}