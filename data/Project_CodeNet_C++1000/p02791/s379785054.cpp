#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

void solve(long long N, std::vector<long long> P){
    ll cnt = 1;
    vector<ll> M(N, P[0]);
    for(ll i = 1; i < N; ++i){
        M[i] = min(P[i], M[i-1]);
        if(P[i] == M[i]) cnt++;
    }
    cout << cnt << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> P(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&P[i]);
    }
    solve(N, std::move(P));
    return 0;
}
