#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rep1(i,n) for(int i=1;i<int(n);i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using Pint = pair<int,int>;
const ll mod = 1e9+7;

int main(){
  ll n,k;
  cin>>n>>k;
  ll r,s,p;
  cin>>r>>s>>p;
  string t;
  cin>>t;

  ll ans=0;
  rep(i,n){
    if(i>=k && t[i]==t[i-k]){
      t[i] = 'x';
      continue;
    }
    if(t[i]=='r') ans+=p;
    if(t[i]=='s') ans+=r;
    if(t[i]=='p') ans+=s;
  }

  cout<<ans<<endl;

  return 0;
}