#include <bits/stdc++.h>
using namespace std;


void solve(long long N, long long K){
    int ans = 1;
    while(N >= K){
        N = N / K;
        ans++;
    }
    //`if(N != 0) ans++;
    cout << ans << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    solve(N, K);
    return 0;
}
