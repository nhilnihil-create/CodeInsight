//Tonight's the night and it is going to happen again and again.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define T ll t; cin>>t; while(t--)
#define mod 1000000007
#define inf 1000000000000000000
#define mem(name,val) memset(name,val,sizeof(name))
#define f(n) for(ll i=0;i<n;i++)
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define endl "\n"
ll gcd(ll a,ll b){if(b==0){return a;}return gcd(b,a%b);}
int vis[1000007];
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif
   int n;cin>>n;int a[n];
   f(n){cin>>a[i];}
   ll res=a[0];
   rep(i,1,n){res=gcd(a[i],res);if(res==1){break;}}
   if(res>1){cout<<"not coprime";}
   else
   {
    int c=0;
    rep(i,0,n)
    {
      for(int j=2;j*j<=a[i];j++)
      {
        if(a[i]%j==0)
        {
          if(vis[j]==1){c=1;goto sos;}
          vis[j]=1;
          while(a[i]%j==0){a[i]/=j;}
        }
      }
      if(a[i]!=1){if(vis[a[i]]==1){c=1;goto sos;}vis[a[i]]=1;}
    }
    sos:
    if(c==1){cout<<"setwise coprime";}
    else{cout<<"pairwise coprime";}
   } 
}