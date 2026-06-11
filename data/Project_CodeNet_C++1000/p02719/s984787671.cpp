#include <bits/stdc++.h>
using namespace std;


void solve(long long N, long long K){
    cout << min(abs(N - K * (N / K)), abs(N - K * (N / K) - K)) << endl;
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
