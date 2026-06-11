#include <bits/stdc++.h>
using namespace std;


void solve(long long N, long long K, std::vector<long long> p){
    vector<double> E(N, 0);
    for(int i = 0; i < N; ++i){
        E[i] = (1 + (double)p[i])/2;
    }
    //for(auto i : E) cout << i << " ";
    //cout << endl;
    vector<double> cse(N+1, 0);
    for(int i = 0; i < N; ++i) cse[i+1] = cse[i] + E[i];
    //for(auto i : cse) cout << i << " ";
    //cout << endl;
    double ans = 0;
    for(int i = 0; i <= N-K; ++i){
        //cout << cse[i+K] << " " << cse[i] << endl;
        ans = max(ans, (cse[i+K]-cse[i]));
    }
    printf("%.12f", ans);
    //cout << ans << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> p(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&p[i]);
    }
    solve(N, K, std::move(p));
    return 0;
}
