#include <bits/stdc++.h>
#define clr(i, j)     memset(i, j, sizeof(i))
using namespace std;
 
#define ll long long
 int dp[3000][3000];
 ll t,n;
 vector<pair<int,int>>p;
 
 int solve(int i,int rem){
     if(rem<=0){return 0;}
     if(i==n){return 0;}
     int &ret=dp[i][rem];
    if(ret!=-1){return ret;}
     ret=solve(i+1,rem);
     ret=max(ret,solve(i+1,rem-p[i].first)+p[i].second);
     return ret;
     
 }
int main()
{
    cin>>n>>t;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        p.push_back({a,b});
    }clr(dp,-1);
    sort(p.begin(),p.end());
    cout<<solve(0,t);
  
   
}