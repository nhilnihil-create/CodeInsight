#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(long long N, long long K, std::vector<long long> p){
    sort(p.begin(), p.end());
    ll ans = 0;
    for(ll i = 0; i < K; ++i) ans = ans + p[i];
    cout << ans << endl;
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
