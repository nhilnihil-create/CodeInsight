#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(long long N, long long K, std::vector<long long> H){
    ll ans;
    if(N <= K) ans = 0;
    else{
        sort(H.begin(), H.end(), greater<ll>());
        //for(auto h : H) cout << h << endl;
        for(ll i = 0; i < K; ++i) H[i] = 0;
        ans = accumulate(H.begin(), H.end(), 0LL);
    }
    cout << ans << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> H(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&H[i]);
    }
    solve(N, K, std::move(H));
    return 0;
}
