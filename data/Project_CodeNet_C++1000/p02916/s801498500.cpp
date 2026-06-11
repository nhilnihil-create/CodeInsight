#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(long long N, std::vector<long long> A, std::vector<long long> B, std::vector<long long> C){
    ll ans = 0;
    for(int i = 0; i < N; ++i){
        ans += B[A[i]-1];
        if(A[i+1] == A[i] + 1) ans += C[A[i]-1];
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
    std::vector<long long> B(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&B[i]);
    }
    std::vector<long long> C(N-1);
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%lld",&C[i]);
    }
    solve(N, std::move(A), std::move(B), std::move(C));
    return 0;
}
