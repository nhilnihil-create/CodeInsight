#include <iostream>
#include <bits/stdc++.h>

#define rep(i,z) for(int i = 0; i<(int)(z); i++)
#define rep1(i,z) for(int i = 1; i<=(int)(z); i++)
 
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;
using pear = pair<int,int>;





int main(){
  ll n,m; cin>>n>>m;
  vector<ll> h(n);
  rep(i,n) cin>>h[i];
  bool good[n];
  rep(i,n) good[i]=true;
  rep(i,m){
      ll a, b; cin>>a >>b;
      a--; b--;
      if(h[a]>h[b]) good[b]=false;
      else if(h[b]>h[a]) good[a]=false;
      else good[a]= good[b]= false;
  }
  ll ans=0;
  rep(i,n) if(good[i]) ans++;
  cout<<ans<<endl;
}
