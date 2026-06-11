#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int H; long long int N;
    cin>>H>>N;
    vector<int> A(N);
    vector<int> B(N);
    for(int i=0; i<N; ++i){
        cin>>A[i]>>B[i];
    }
    long long int dp[H+(*max_element(A.begin(), A.end()))];
    dp[0] = 0;
    long long int x = H+(*max_element(A.begin(), A.end()));
    for(int i=1; i<x; ++i){
        dp[i] = INT_MAX;
        for(int j=0; j<N; ++j){
            long long int current = B[j];
            if(A[j]<i) current += dp[i-A[j]];
            dp[i] = min(dp[i], current);
        }
    }
    long long int ans = INT_MAX;
    for(int i=H; i<x; ++i) ans = min(ans, dp[i]);
    cout<<ans<<endl;
}