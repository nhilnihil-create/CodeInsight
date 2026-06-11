#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i,n) for (int i = 0; i < (n); ++i)


void solve(long long N, std::vector<long long> A){
    sort(A.begin(),A.end(),greater<long long>());
    ll ans = 0;
    rep(i,N){
        if(i == 0) continue;
        ll d = i/2;
        ans += A[d];
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
