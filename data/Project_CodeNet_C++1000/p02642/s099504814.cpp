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
 ll n;
 cin>>n;
 vector<ll>a(n);
 rep(i,n)cin>>a[i];
 vector<ll>v(1000007,-1);
 rep(i,n){
     if(v[a[i]]==-1){
         for(ll l=a[i];l<=1000007;l+=a[i]){
            if(v[l]==-1){v[l]=1;}
             else{v[l]=2;}
         }
     }else{
         v[a[i]]=2;}
 }
 ll ans=0;
 rep(i,n)if(v[a[i]]==1){
     ans++;}
 cout<<ans<<endl;
 }

 


 

 


