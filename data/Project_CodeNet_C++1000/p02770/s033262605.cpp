#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const int INF=1e18;
const int MOD=1e9+7;

int d[5000],e[5000],cou[5000];
int k, q;

void solve(){
    int n, x, m; cin >> n >> x >> m; x %= m;
    int sum = 0; 
    REP(i,k){
        e[i] = d[i] % m + ( d[i] % m == 0 ? m : 0 );
        sum += e[i];
    }
    sum *= (n-1) / k;
    sum += x;
    REP(i, (n-1)%k) sum += e[i];
    cout << n - 1 - (sum / m) + (x / m) <<endl;
}

signed main(){
    cin >> k >> q;
    REP(i,k) cin >> d[i];
    REP(i,q) solve();
}