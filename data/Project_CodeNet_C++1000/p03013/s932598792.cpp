#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int n,m;
  cin >> n >> m;
  vector<int> a(m);
  vector<bool> is(n+1,true);
  rep(i,m){
    cin >> a.at(i);
    is.at(a.at(i))=false;
  }
  vector<ll> ans(n+1,0);
  ans.at(0)=1;
  for(ll i=1;i<n+1;i++){
    if(is.at(i)==false && is.at(1+i)==false){
      cout << 0;
      return 0;
    }
  }
  ll p=1e9+7;
  for(ll i=1;i<n+1;i++){
    if(is.at(i)==false){
      continue;
    }
    if(i==1){
      ans.at(i)=1;
      continue;
    }
    ans.at(i)=ans.at(i-1)+ans.at(i-2);
    ans.at(i)=ans.at(i)%p;
  }
  cout <<ans.at(n);
}