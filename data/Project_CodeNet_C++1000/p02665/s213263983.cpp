#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vi a(n+1); rep(i,n+1) cin >> a[i];
  vector<ll> mx(n+1),mn(n+1);
  mx[n] = mn[n] = a[n];
  for(int i = n; 0 < i; i--){
    mx[i-1] = mx[i] + a[i-1];
    mn[i-1] = (mn[i]+1)/2 + a[i-1];
  }
  ll ans = 0, num = 1;
  rep(i,n+1){
    chmin(num,mx[i]);
    if(num < mn[i]){
      cout << -1;
      return 0;
    }
    ans += num;
    num -= a[i];
    num *= 2;
  }
  cout << ans;
  cout << "\n";
  return 0;
}
