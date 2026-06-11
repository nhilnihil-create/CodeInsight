#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i,n) for (int i = 0; i < (n); ++i)


void solve(long long N, std::vector<long long> A){
    vector<ll> res(10000005);
    ll ans = 0;
    rep(i,N){
        ll d = A[i];
        if(res[d] != 0){
            res[d] = 2;
            continue;
        }
        for(ll j = d; j <= 10000005; j += d){
            res[j] += 1;
        }
    }
    rep(i,N){
        ll d = A[i];
        if(res[d] == 1) ans++;
    }
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
