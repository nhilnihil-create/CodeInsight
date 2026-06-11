#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
//#define ll long long
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define rep_rev(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
ll t1,t2,t3;
const ll mod = 1000000007;
const int INF = 1e9;
const ll INFLONG = 1e18;

int main(){
  ll n;
  cin >> n;
  vector<vector<ll>> vec(n,vector<ll>(n));
  rep(i,n){
    rep(j,n){
      cin >> vec[i][j];
    }
  }
  vector<ll> arr(n,0);
  arr[0] = 1;
  priority_queue<pair<ll,ll>> pq;
  rep(i,n){
    if(vec[0][i] != -1){
      pq.push(make_pair(-vec[0][i],i));
    }
  }
  pair<ll,ll> pa;
  ll ans = 0;
  while(!pq.empty()){
    pa = pq.top();
    pq.pop();
    if(arr[pa.second] == 0){
      arr[pa.second] = 1;
      ans -= pa.first;
      rep(i,n){
        if(vec[pa.second][i] != -1){
          pq.push(make_pair(-vec[pa.second][i],i));
        }
      }
    }
  }
  cout << ans << endl;
}
