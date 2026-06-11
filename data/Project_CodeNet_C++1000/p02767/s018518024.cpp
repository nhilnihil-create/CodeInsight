#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

void solve(long long N, std::vector<long long> X){
    vector<ll> s(100, 0);
    for(ll i = 0; i < 100; ++i){
        for(ll j = 0; j < N; ++j){
            s[i] += (i+1-X[j]) * (i+1-X[j]);
        }
    }
    ll ans = INF;
    for(int i = 0; i < 100; ++i) ans = min(ans, s[i]);
    cout << ans << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> X(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&X[i]);
    }
    solve(N, std::move(X));
    return 0;
}
