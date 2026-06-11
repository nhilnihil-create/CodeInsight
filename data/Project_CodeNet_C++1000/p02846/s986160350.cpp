#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  ll TA,TB,AA,AB,BA,BB;
  cin>>TA>>TB>>AA>>AB>>BA>>BB;
  ll da = TA*(BA-AA),db=TB*(BB-AB);
  ll c = da+db;
  bool inf = false;
  ll ans = 0LL;
  if((da>0&&c>0)||(da<0&&c<0))ans = 0LL;
  else if(c==0LL) inf = true;
  else {
    ll cnt = db/c;
    ans = 2LL*cnt-1LL;
    if(db%c==0LL)ans--;
  }
  if(inf) cout<<"infinity"<<endl;
  else cout<<ans<<endl;
}