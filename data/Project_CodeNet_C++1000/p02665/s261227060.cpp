#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORR(i,m,n) for(int i = m - 1; i >= n; i--)
#define ALL(v) v.begin(), v.end()
#define itn int
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl
#define YES() cout << "YES" << endl
#define NO() cout << "NO" << endl
#define println(x) cout << x << endl
#define print(x) cout << x << " "
template<typename T, typename U>
inline bool CMAX(T &m, U x) { if (m < x) { m = x; return true; } return false; }
template<typename T, typename U>
inline bool CMIN(T &m, U x) { if (m > x) { m = x; return true; } return false; }

typedef long long lint;
typedef long double ldouble;
const int INF = 1e9;
const lint LINF = 1e18;
const int MOD = 1e9+7;
int main(){
    int n;
    cin >> n;
    lint child = 0;
    lint ans = 0;
    vector<lint> a(n + 1);
    vector<lint> f(n + 1);
    REP(i,n + 1) cin >> a[i];
    f[0] = 1;
    if(f[0] < a[0]){
        println(-1);
        return 0;
    }
    REP(i,n){
        if((f[i] - a[i]) <= LINF / 2)
            f[i + 1] = (f[i] - a[i]) * 2;
        else{
            f[i + 1] = LINF;
        }
        if(f[i + 1] < a[i + 1]){
            println(-1);
            return 0;
        }
    }
    REPR(i,n + 1){
        if(i == n){
            ans += a[i];
            child = a[i];
        }else{
            lint res = min(child + a[i],f[i]);
            ans += res;
            child = res;
        }
    }
    println(ans);
    return 0;
}