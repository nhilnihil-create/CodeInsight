#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i,n) for (int i = 0; i < (n); ++i)

const ll MAX = 1e18;

void solve(long long N, std::vector<long long> A){
    ll ans = 1;
    rep(i,N){
        if(A[i] == 0){
            cout << 0 << endl;
            return;
        }
    }

    rep(i,N){
        if(A[i] <= MAX/ans){
            ans *= A[i];
        }else{
            cout << -1 << endl;
            return;
        }
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
