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
template<typename T, typename U>
inline bool CMAX(T &m, U x) { if (m < x) { m = x; return true; } return false; }
template<typename T, typename U>
inline bool CMIN(T &m, U x) { if (m > x) { m = x; return true; } return false; }

typedef long long lint;
typedef long double ldouble;
const int INF = 1e9;
const lint LINF = 1e18;
const int MOD = 1e9+7;


lint calc(lint a,lint b){
    if(b == 0)return 1;
    if(b % 2 == 0){
        lint c = calc(a,b/2);
        return (c*c) % MOD;
    }else{
        return (a * calc(a,b-1)) %MOD;
    }
}
int main(){
    int n;
    int a,b;
    cin >> n >> a >> b;
    lint ans = calc(2,n) - 1;
    lint x = 1;
    lint y = 1;
    REP(i,a){
        x = (x * (n - i)) % MOD;
        y = (y * (i+1)) % MOD;
    } 
    lint wal = calc(y,MOD - 2);
    ans = (ans + MOD - (x * wal)%MOD) % MOD;
    x = 1;
    y = 1;
    
    REP(i,b){
        x = (x * (n - i)) % MOD;
        y = (y * (i+1)) % MOD;
    } 
    wal = calc(y,MOD - 2);
    ans = (ans + MOD - (x * wal)%MOD)%MOD;
    cout << ans % MOD << endl;
    return 0;
}