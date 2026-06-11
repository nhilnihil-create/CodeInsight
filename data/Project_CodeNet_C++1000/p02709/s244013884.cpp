#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int N;
    cin>>N;
    ll dp[2020][2020],ans=0;
    vector<pair<ll,int>> A(N);
    for(int i=0;i<N;i++){
        cin>>A.at(i).first;
        A.at(i).second=i;
    }
    sort(A.begin(),A.end(),greater<pair<ll,int>>());
    for(int j=1;j<=N;j++){
        dp[0][j]=dp[0][j-1]+A.at(j-1).first*(N-j-A.at(j-1).second);
    }
    for(int i=1;i<=N;i++){
        dp[i][0]=dp[i-1][0]+A.at(i-1).first*(A.at(i-1).second-i+1);
        for(int j=1;j<=N-i;j++){
            dp[i][j]=max(dp[i][j-1]+A.at(i+j-1).first*(N-j-A.at(i+j-1).second),dp[i-1][j]+A.at(i+j-1).first*(A.at(i+j-1).second-i+1));
        }
        ans=max(ans,dp[i][N-i]);
    }
    cout<<ans<<endl;
}