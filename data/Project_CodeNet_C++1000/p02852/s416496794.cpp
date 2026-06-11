#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,m;
  string s;

  cin >> n >> m >> s;

  ll dp[n+1]={};

  ll p=n;
  bool owa=false;

  while(p!=0){
    ll k=0;
    for(ll i=1;i<=m;i++){
      if(p-i==-1){
        owa=true;
        break;
      }
      if(s[p-i]=='1')dp[p-i]=-1;
      else{
        k=i;
        dp[p-i]=dp[p]+1;
      }
    }

    if(k==0){
      cout << -1 << endl;
      return 0;
    }


    if(owa)p=0;
    else p=p-k;
  }
  if(dp[0]==0)cout << -1 << endl;
  else{
    p=0;
    ll a=dp[p];
    vector<ll> v;
    bool mugokuka=true;
    while(p!=n){
      for(ll i=1;i<=m;i++){
        if(dp[p+i]+1==dp[p]){
          v.push_back(i);
          mugokuka=false;
          p=p+i;
          break;
        }
      }
    }
    for(ll i=0;i<v.size();i++)cout << v[i] << " " ;
    
    
  }

}