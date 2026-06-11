#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
#define INF (1e9)
int main() {
    int H,N;cin>>H>>N;
    vi A(N),B(N);
    for (int i = 0; i < N; i++){
        cin>>A[i]>>B[i];
    }
    vi dp(H+1,INF);
    dp[H]=0;
    for (int h = H; h >=0 ; h--){
        for (int i = 0; i < N; i++){
            if(h-A[i]<0)dp[0]=min(dp[0],dp[h]+B[i]);
            else dp[h-A[i]]=min(dp[h-A[i]],dp[h]+B[i]);
        }
    }
    cout<<dp[0]<<endl;
}