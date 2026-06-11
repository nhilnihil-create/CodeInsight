#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define VIEW(x) do {cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;} while(0)
#define ALL(x) (x).begin(),(x).end()
template<class T>bool umax(T &a, const T &b) {if(a<b){a=b;return 1;}return 0;}
template<class T>bool umin(T &a, const T &b) {if(b<a){a=b;return 1;}return 0;}

template<typename A,size_t N,typename T> void FILL(A (&array)[N],const T &val){fill((T*)array,(T*)(array+N),val);}
template<typename T> void FILL(vector<T> &v, const T &x) {fill(v.begin(), v.end(), x);}
template<typename T> void FILL(vector<vector<T>> &v, const T &x) {for(auto &i:v)fill(i.begin(), i.end(), x);}


int main() {
  int n; cin >>n;
  vector<ll> leaf(n+1);
  rep(i, n+1) cin >> leaf[i];

  vector<ll> non_leaf(n+1);

  if (leaf[0]>1) {
    cout << -1 << endl;
    return 0;
  }
  else if (leaf[0]==1) {
    if (n==0) cout << 1 << endl;
    else cout << -1 << endl;
    return 0;
  }

  non_leaf[0] = 1;
  non_leaf[n] = 0;

  for(int d = n-1; d >= 1; d--) {
    ll children = leaf[d+1] + non_leaf[d+1];
    non_leaf[d] = children;
  }

  for(int d = 1; d <= n; d++) {
    ll parents = non_leaf[d-1];
    if(parents*2 < leaf[d]) {
      cout << -1 << endl;
      return 0;
    }
    umin(non_leaf[d], parents*2-leaf[d]);
  }

  ll ans = 0;
  for(int d = 0; d <= n; d++) ans += leaf[d] + non_leaf[d];
  cout << ans << endl;
}
