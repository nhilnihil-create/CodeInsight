#include <bits/stdc++.h>
using namespace std;


void solve(long long N, long long M, std::vector<long long> H, std::vector<long long> A, std::vector<long long> B){
    vector<vector<long long> > HH(N+1, vector<long long>(1));
    for(int i = 0; i < M; ++i){
        HH[A[i]].push_back(B[i]);
        HH[B[i]].push_back(A[i]);
    }
    /*
    for(int i = 1; i <= N; ++i){
        cout << i << ":" << H[i] << endl;
        for(auto j : HH[i]){
            cout << H[j] << " ";
        }
        cout << endl;
    }
    */
    long long ans = 0;
    for(int i = 1; i <= N; ++i){
        long long maxval = 0;
        for(auto j : HH[i]){
            maxval = max(maxval, H[j]);
        }
        //cout << H[i] << " " << maxval << endl;
        if(H[i] > maxval) ans++;
    }
    cout << ans << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> H(N+1);
    H[0] = 0;
    for(int i = 1 ; i <= N ; i++){
        scanf("%lld",&H[i]);
    }
    std::vector<long long> A(M);
    std::vector<long long> B(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
    }
    solve(N, M, std::move(H), std::move(A), std::move(B));
    return 0;
}
