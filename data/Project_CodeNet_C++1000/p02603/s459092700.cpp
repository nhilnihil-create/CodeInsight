#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a.at(i);
  }
  ll ans=1000;
  rep(i,n-1){
    ll p=ans/a.at(i);
    ll q=ans%a.at(i);
    if(a.at(i)<a.at(i+1)){
      ans=p*a.at(i+1)+q;
    }
  }
  if(ans<1000){
    cout << 1000;
  }else{
    cout << ans;
  }
}
    
  