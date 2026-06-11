#include <bits/stdc++.h>
#define rep(i,e,n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int inf=1000000007;

int main(){
  int x,y,a,b,c;
  cin >> x >> y >> a >> b >>c;
  priority_queue<ll> aa;
  priority_queue<ll> ba;
  priority_queue<ll> ca;
  
  rep(i,0,a) {
    ll val;
    cin >> val;
    aa.push(val);
  }
  rep(i,0,b) {
    ll val;
    cin >> val;
    ba.push(val);
  }
  rep(i,0,c) {
    ll val;
    cin >> val;
    ca.push(val);
  }
  ll ans=0;
  rep(i,0,x){
    ll aav = aa.top();
    ll cav = ca.top();
    if(aav>=cav){
      ans += aav;
      aa.pop();
    }
    else{
      ans += cav;
      ca.pop();
      ca.push(aav);
      aa.pop();
    }
  }
  rep(i,0,y){
    ll bav = ba.top();
    ll cav = ca.top();
    if(bav>cav){
      ans += bav;
      ba.pop();
    }
    else{
      ans += cav;
      ca.pop();
      ca.push(bav);
      ba.pop();
    }
  }
  cout << ans << endl;

  return 0;
}