#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using ll = long long;

#include<bits/stdc++.h>


void solve(long long N, long long K, std::vector<long long> A){

    for(int i = 0;i < K;i++){
        vector<ll> B(N);
        for(int i = 0;i < N;i++){
            int l = max(0LL, i - A[i]);
            int r = min(N - 1, i + A[i]);
            B[l]++;
            if(r+1 < N)B[r+1]--;
        }
        for(int i = 1;i < N;i++)B[i] += B[i - 1];
        if(A == B){
            break;
        }else{
            A = B;
        }
    }
    for(int i = 00;i < N;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, K, std::move(A));
    return 0;
}
