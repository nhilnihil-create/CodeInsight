#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;


//---------- べき乗 ----------
Int power(Int a, Int n){
    Int MOD = 1e9+7;
    if(a == 0) return 0;
    if(n == 0) return 1;
    
    Int res = 1;
    while(n > 0){
        if(n % 2 == 1) res = res * a % MOD;
        a = a * a % MOD; n /= 2;
    }
    return res;
}


int main(){
    int N; cin >> N;
    vector<Int> A(N+1);
    rep(i,N+1) cin >> A[i];

    if(N == 0 && A[0] != 1) {cout << -1 << endl; return 0;}

    vector<pair<Int,Int>> minmax_v(N+1);
    minmax_v[N] = {A[N], A[N]};

    for(int d = N-1; d>=0; d--){
        Int M = minmax_v[d+1].second + A[d];
        Int m = max((Int)1, minmax_v[d+1].first/2 + A[d]);

        if(d < 30 && m > power(2,d)) {cout << -1 << endl; return 0;}

        minmax_v[d] = {m,M}; 
    }


    vector<Int> v(N+1); Int ans = 1;
    v[0] = 1;
    rep1(d,N){
        v[d] = min((v[d-1]-A[d-1]) * 2, minmax_v[d].second);
        if(d < 30) v[d] = min(v[d], power(2,d));

        if(v[d] < A[d]) {cout << -1 << endl; return 0;}
        ans += v[d];
    }

    cout << ans << endl;
}