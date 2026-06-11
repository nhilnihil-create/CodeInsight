#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin>>n;
  vector<ll> a(n+1), b(n);
  rep (i, n+1) cin>>a.at(i);
  rep (i, n) cin>>b.at(i);
  ll ans = 0;
  
  rep (i, n) {
    //持ち場だけ
    if(b.at(i)<=a.at(i)) {
      ans+=b.at(i);
    }
    //救援可能
    else {
      ans+=a.at(i);
      b.at(i)-=a.at(i);
      if(b.at(i)>=a.at(i+1)) {
        ans+=a.at(i+1);
        a.at(i+1)=0;
      }
      else {
        ans+=b.at(i);
        a.at(i+1)-=b.at(i);
      }
    }
  }
  cout<<ans<<endl;
}