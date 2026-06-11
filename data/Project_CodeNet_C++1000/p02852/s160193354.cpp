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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  string s;
  cin >> s;

  reverse(s.begin(), s.end());

  int start = 0;
  int can_go = 0;

  vector<int> ans;
  for(int now = 0; now <= N; now++){

    if(s[now] == '0'){
      can_go = now;
    }

    if(now - start == M || now == N){
      
      if(can_go == start){
        cout << -1 << endl;
        return 0;
      }

      ans.push_back(can_go - start);

      start = can_go;
    }
  }

  rep(i, ans.size()){
    cout << ans[ans.size()-1-i] << " ";
  }
  cout << endl;





  return 0;
}
