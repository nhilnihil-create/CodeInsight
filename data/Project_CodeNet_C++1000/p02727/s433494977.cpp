#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;


int main(){
  int x,y,a,b,c;
  cin >> x >> y >> a >> b >> c;
  priority_queue<ll> aa,bb,cc;
  rep(i,a){ll g;cin >> g;aa.push(g);}
  rep(i,b){ll g;cin >> g;bb.push(g);}
  rep(i,c){ll g;cin >> g;cc.push(g);}
  ll ans=0;

  rep(i,x){cc.push(aa.top()); aa.pop();}
  rep(i,y){cc.push(bb.top()); bb.pop();}
  rep(i,x+y){
    ans+=cc.top();
    cc.pop();
  }
  cout << ans << endl;
}
