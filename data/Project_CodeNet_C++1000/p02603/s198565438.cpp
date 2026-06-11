#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int>pa;

const int N=2e5+100;

ll dp[100]; ///到i个时最大的价值
int a[100];
int main()
{

    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[1]=1000;
    for(int i=1;i<n;i++){
        dp[i+1]=max(dp[i],dp[i]/a[i]*a[i+1]+dp[i]%a[i]);
    }
    cout<<dp[n];
    return 0;
}

