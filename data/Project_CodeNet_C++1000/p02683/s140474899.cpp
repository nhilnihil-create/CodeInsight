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




ll mod=1e9+7;
ll dp[2000+4];

vector<pair<ll,ll>>p;

vector<ll> to[100005];
ll inf =1000000007;
int main()
{
  ll n,m,x;
  cin>>n>>m>>x;
  vector<ll>c(n);
  vector<vector<ll>>a(n,vector<ll>(m));
  rep(i,n){
      cin>>c[i];
      rep(j,m)cin>>a[i][j];
  }
  ll ans=1000000007;
  rep(i,1<<n){
      vector<ll>skill(m,0);
      ll sum=0;
      for(ll ii=0;ii<n;ii++){
          if(i>>ii&1){
            sum+=c[ii];
            rep(j,m)skill[j]+=a[ii][j];
          }
      }
      ll ok=1;
      rep(i,m){
          if(skill[i]<x)ok=0;
      }
      if(ok)ans=min(ans,sum);
  }
  if(ans==1000000007){
      cout<<-1<<endl;
      return 0;
  }
  cout<<ans<<endl;
 }

 


 

 


