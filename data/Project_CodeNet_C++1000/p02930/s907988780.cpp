#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int ans[510][510];

void solve(vector<int> v, int num){

  if(v.size()==1){
    return;
  }

  int n = v.size();
  int mid = (n + 1)/2;

  for(int i = 0; i < mid; i++){
    for(int j = mid; j < n; j++){
      ans[v[i]][v[j]] = num;
    }
  }

  vector<int> vec1, vec2;
  for(int i = 0; i < mid; i++){
    vec1.push_back(v[i]);
  }
  for(int i = mid; i < n; i++){
    vec2.push_back(v[i]);
  }

  solve(vec1, num+1);
  solve(vec2, num+1);

  return;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> a(n);
  rep(i, n){
    a[i] = i;
  }

  solve(a, 1);

  rep(i, n-1){
    rep(j, i+1, n){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
