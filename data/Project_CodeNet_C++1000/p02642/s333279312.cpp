#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i,n) for (int i = 0; i < (n); ++i)


void solve(long long N, std::vector<long long> A){
    ll ans = 0;
    vector<ll> p(1000006);
    rep(i,N){
        if(p[A[i]]) {
            p[A[i]] = 2;
            continue;
        }

        for(int j = A[i]; j < 1000006; j += A[i]){
            p[j] += 1;
        }
    }

    rep(i,N){
        if(p[A[i]] == 1) ans++;
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
