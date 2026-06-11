#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
ll INF = 1'000'000'000'000'000'000;

int main(){
  int n;
  cin >> n;
  ll ans = 1;
  vector<ll> a(n);
  rep(i,n){
    cin >> a.at(i);
    if (a.at(i) == 0){
      cout << 0 << endl;
      return 0;
    }
  }
  rep(i,n){
    if (INF/ans < a.at(i) || ans > INF){
      cout << -1 << endl;
      return 0;
    }
    ans *= a.at(i);
  }
  cout << ans << endl;
  return 0;
}