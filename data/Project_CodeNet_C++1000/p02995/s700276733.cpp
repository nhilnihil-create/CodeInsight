#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll a, b, c, d, ans;
  cin>>a>>b>>c>>d;
  
  //最小公倍数を求める
  ll x=max(c,d), y=min(c,d), g;
  while(x%y!=0){
    x=x%y;
    swap(x, y);
  }
  g = c*d/y;
  
  ll all = b-a+1;
  ll cc = b/c-(a-1)/c;
  ll dd = b/d-(a-1)/d;
  ll gg = b/g-(a-1)/g;
  
  ans = all-(cc+dd-gg);
  cout<<ans<<endl;
}