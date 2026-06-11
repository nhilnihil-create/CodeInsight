#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<endl;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }



int main(int argc, char const *argv[]) {
  int n, m;
  cin >> n >> m;
  ll ans = 0;
  priority_queue<ll> pq;
  rep(i, n) {
    ll a;cin >> a;
    pq.push(a);
  }
  rep(i,m){
    ll x=pq.top();
    pq.pop();
    pq.push(x / 2);
  }

  while(!pq.empty()){
    ans += pq.top();
    pq.pop();
  }
  cout << ans << endl;
  return 0;
}