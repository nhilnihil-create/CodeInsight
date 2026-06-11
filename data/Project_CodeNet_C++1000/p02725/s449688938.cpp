#include <bits/stdc++.h>
using namespace std;


void solve(long long K, long long N, std::vector<long long> A){
    vector<long long> dA(N);
    for(int i = 0; i < N; ++i){
        if(i == 0) dA[i] = A[i] + K - A[N-1];
        else{
            dA[i] = A[i] - A[i-1];
        }
    }
    cout << K - *max_element(dA.begin(), dA.end()) << endl;
    return;
}

int main(){
    long long K;
    scanf("%lld",&K);
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(K, N, std::move(A));
    return 0;
}
