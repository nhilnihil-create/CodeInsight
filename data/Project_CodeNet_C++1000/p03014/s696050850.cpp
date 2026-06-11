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
  
vector<vector<ll>> A(H,vector<ll> (W+2,0));
  for(ll i=0;i<H;i++) {
ll count=0;
    for(ll j=1;j<W+1;j++) {
if(vec[i][j-1]=='#') {
count++;
}
      A[i][j]=count;
    }
    A[i][W+1]=count+1;
  }
  
  
  vector<vector<ll>> B(W,vector<ll>(H+2,0));
  for(ll i=0;i<W;i++) {
    ll count=0;
    for(ll j=1;j<H+1;j++) {
      if(vec[j-1][i]=='#') {
count++;
      }
      B[i][j]=count;
    }
    B[i][H+1]=count+1;
  }
  
  ll ans=0;
  for(ll i=0;i<H;i++) {
for(ll j=0;j<W;j++) {
if(vec[i][j]=='#') {
continue;
}
  ll p=lower_bound(all(A[i]),A[i][j+1]+1)-lower_bound(all(A[i]),A[i][j+1])-1;
  ll q=lower_bound(all(B[j]),B[j][i+1]+1)-lower_bound(all(B[j]),B[j][i+1])-1;
  ans=max(ans,p+q-1);
}
  }
  
  cout<<ans<<endl;
}


  