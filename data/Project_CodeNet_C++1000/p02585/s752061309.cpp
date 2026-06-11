#include <bits/stdc++.h>
#define rep(i,n) for(long long i=0; i<n; i++)
#define Rep(i,n) for(long long i=1; i<n; i++)
#define ll long long
#include <math.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>


using namespace std;
#define PI acos(-1)
using P =pair<ll,ll>;


ll m=1000000007;

ll mod=1e9+7;
ll dp[2000+4];


int main()
{
 ll n,k;
 cin>>n>>k;
 vector<ll>p(n);
 vector<ll>c(n);
 rep(i,n)cin>>p[i];
 rep(i,n)cin>>c[i];
 rep(i,n)p[i]--;
 
 ll ans=-1000000000000; 
 rep(i,n){
     ll now=i;
     ll cnt=0;
     ll tot=0;
     while(1){
        now=p[now];
        tot+=c[now];
        cnt++;
        if(now==i)break;
     }
     now=i;
     ll sum=0;
     ll tmp=k;
     ll tmp2=0;
     while(0<tmp){
        now=p[now];
        tmp--;
        tmp2++;
        sum+=c[now];
        ans=max(ans,sum);
        if(0<tot){
         ll e=tmp/cnt;
         ans=max(ans,sum+tot*e);
        }
        if(tmp2==cnt+1)break;
     }
 }
 cout<<ans<<endl;
}
 


 

 


