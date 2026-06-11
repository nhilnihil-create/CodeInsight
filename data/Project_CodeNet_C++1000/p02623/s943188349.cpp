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


ll ans=0;

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
  vector<ll> a(n);
  rep(i,n)cin>>a[i];
  vector<ll> b(m);
  rep(i,m)cin>>b[i];
  
  vector<ll> A={0};
  rep(i,n)A.push_back(A[i]+a[i]);
  vector<ll> B={0};
  rep(i,m)B.push_back(B[i]+b[i]);
  ll j=B.size()-1;
  rep(i,A.size()){
      if(k<A[i])break;
      else{
          while(k<A[i]+B[j]){
              j--;
          }
          ans=max(ans,i+j);
      }
  }
  cout<<ans<<endl;
}

