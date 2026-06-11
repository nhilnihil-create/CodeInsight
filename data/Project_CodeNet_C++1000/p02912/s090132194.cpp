#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n,m;
  cin >> n >> m;
  priority_queue<ll> q;

  rep(i,n){
    ll a;
    cin >> a;
    q.push(a);
  }

  while(m>0){
    ll t = q.top(); q.pop();
    t /= 2;
    q.push(t);
    m--;
  }
  ll ans = 0;
  while(!q.empty()){
    ll t = q.top(); q.pop();
    ans += t;
  }
  cout << ans << endl;
}
