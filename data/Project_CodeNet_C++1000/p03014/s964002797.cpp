#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()


int main() {
  ll H,W;
  cin>>H>>W;
  vector<string> vec(H);
  for(ll i=0;i<H;i++) {
cin>>vec[i];
  }
  
  vector<vector<ll>> a(H,vector<ll>(0));
  vector<vector<ll>> b(W,vector<ll>(0));
vector<vector<ll>> A(H,vector<ll> (W,0));
  for(ll i=0;i<H;i++) {
ll count=0;
    ll sum=0;
    for(ll j=0;j<W;j++) {
if(vec[i][j]=='#') {
count++;
  a[i].push_back(sum);
  sum=-1;
}
      A[i][j]=count;
      sum++;
    }
    
a[i].push_back(sum);
    
    
  }
  
  
  vector<vector<ll>> B(W,vector<ll>(H,0));
  for(ll i=0;i<W;i++) {
    ll count=0;
    ll sum=0;
    for(ll j=0;j<H;j++) {
      if(vec[j][i]=='#') {
count++;
        b[i].push_back(sum);
       
        sum=-1;
      }
      B[i][j]=count;
      sum++;
    }
    b[i].push_back(sum);
    
  }
  
  ll ans=0;
  for(ll i=0;i<H;i++) {
for(ll j=0;j<W;j++) {
if(vec[i][j]=='#') {
continue;
}
  ll p=A[i][j];
  ll q=B[j][i];
  
  ans=max(ans,a[i][p]+b[j][q]-1);
}
  }
  
  cout<<ans<<endl;
}


  