#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define PRINT(x) cout<<(x)<<endl
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
#define PB push_back
#define MP make_pair



int main() {
    int M; cin >> M;
    vector<ll> d(M), c(M); REP(i, M) cin >> d[i] >> c[i];

    ll d_sum = 0;
    ll c_sum = 0;
    REP(i, M) {
        d_sum += d[i] * c[i];
        c_sum += c[i];
    }    

    ll ans = (d_sum - 1) / 9 + (c_sum - 1);
    PRINT(ans);    
    return 0;
}