#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll lcm(ll a,ll b){return a*b/__gcd(a,b);}
int main()
{
    int n;
    cin>>n;
    int dp[n+5]={};
    for(int i=1,x;i<n;i++)
    {
        cin>>x;
        dp[x]++;
    }
    for(int i=1;i<=n;i++)cout<<dp[i]<<" \n"[i==n];
}
