#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<int, int> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> jobs(m);
  rep(i,n){
    ll a,b;
    cin >> a >> b;
    if(a > m) continue;
    jobs[m-a].push_back(b);
  }

  priority_queue<ll> q;
  ll ans = 0;
  for(ll i = m-1; i >= 0; i--){
    for(ll b : jobs[i]){
      q.push(b);
    }
    if(!q.empty()){
      ans += q.top();
      q.pop();
    }
  }
  cout << ans << endl;
  return 0;
}