#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n),ans(n);
  rep(i,n){
    cin >> a.at(i);
    if(i!=0 &&a.at(i)==0){
      cout << 0;
      return 0;
    }
    if(i==0 && a.at(i)!=0){
      cout << 0;
      return 0;
    }
    if(a.at(i)==0){
      continue;
    }
    ans.at(a.at(i)-1)++;
  }
  ll ans1=1,mod=998244353;
  rep(i,n-1){
    if(ans.at(i)==0 && ans.at(i+1)!=0){
      cout << 0;
      return 0;
    }
    for(ll j=0;j<ans.at(i+1);j++){
      ans1*=ans.at(i);
      ans1%=mod;
    }
  }
  cout << ans1;
}
  