#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long

int d[5000],e[5000];
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