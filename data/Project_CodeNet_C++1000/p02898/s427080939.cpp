#include <bits/stdc++.h>
using namespace std;


void solve(long long N, long long K, std::vector<long long> h){
    long long ans = 0;
    for(int i = 0; i < N; ++i){
        if(h[i] >= K) ans++;
    }
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> h(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&h[i]);
    }
    solve(N, K, std::move(h));
    return 0;
}
