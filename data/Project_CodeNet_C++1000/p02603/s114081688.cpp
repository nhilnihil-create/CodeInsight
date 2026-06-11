#include<iostream>
using namespace std;
long long N;
int main(){
    cin>>N;
    long long A[N],dp[N]={1000LL};
    for(int i=0;i<N;i++)cin>>A[i];
    for(int i=1;i<N;i++){
        dp[i]=dp[i-1];
        for(int j=0;j<i;j++)dp[i]=max(dp[i],A[i]*(dp[j]/A[j])+(dp[j]%A[j]));
    }
    cout<<dp[N-1]<<endl;
    return 0;
}