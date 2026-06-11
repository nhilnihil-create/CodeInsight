#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,k,s;
  cin >> n >> k >> s;
  vector<ll> ans(n,-1);
  rep(i,k){
    ans.at(i)=s;
  }
  rep(i,n){
    if(ans.at(i)==-1){
      if(s==1e9){
        ans.at(i)=1;
      }else{
        ans.at(i)=1e9;
      }
    }
  }
  rep(i,n){
    cout << ans.at(i) << " ";
  }
}