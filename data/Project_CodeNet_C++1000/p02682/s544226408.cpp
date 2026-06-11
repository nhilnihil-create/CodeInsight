#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i,n) for (int i = 0; i < (n); ++i)


void solve(long long A, long long B, long long C, long long K){
    ll ans = 0;
    if(K > 0){
       ans += min(K,A); 
       K -= A;
    }
    if(K > 0){
        K -= B;
    }
    if(K > 0){
        ans -= min(K,C);
        K -= C;
    }
    cout << ans << endl;
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long C;
    scanf("%lld",&C);
    long long K;
    scanf("%lld",&K);
    solve(A, B, C, K);
    return 0;
}
