#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  int n; cin >> n;
  vi a(n); rep(i,n) cin >> a[i];
  ll x = 0;
  rep(i,n){
    if(i % 2 == 0) x += a[i];
    else x -= a[i];
  }
  x /= 2;
  vi ans(n);
  ans[0] = x;
  rep(i,n-1) ans[i+1] = a[i] - ans[i];
  rep(i,n) cout << ans[i]*2 << " ";
  cout << "\n";
  return 0;
}
