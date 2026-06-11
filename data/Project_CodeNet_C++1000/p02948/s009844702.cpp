#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";
ll mod = 1000000007;
int main(){
  ll n,m; cin >> n >> m;
  vector<vector<ll>> v(m);
  rep(i,n){
    ll a,b; cin >> a >> b;
    if(a>m) continue;
    v[a-1].push_back(b);
  }
  priority_queue<ll> pq;
  ll ans = 0;
  rep(i,m){
    for(auto e:v[i]){
      pq.push(e);
    }
    if(pq.empty()) continue;
    ans+=pq.top();
    pq.pop();
  }
  cout << ans << endl;
  return 0;
}