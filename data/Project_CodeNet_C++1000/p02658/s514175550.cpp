#include <bits/stdc++.h>
using namespace std;


void solve(long long N, std::vector<long long> A){
    for(auto a : A){
        if(a == 0){
            cout << 0 << endl;
            return;
        }
    }
    long long ans = 1;
    for (int i = 0; i < N; i++)
    {
        if(A[i] <= 1000000000000000000/ans) ans *= A[i];
        else{
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
    return;
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
