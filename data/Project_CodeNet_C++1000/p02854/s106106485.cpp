#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;
const ll INF = 1e19;

void chmin(ll &a, ll b){
  if(a > b) a = b;
}

int main() { 
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n){
    cin >> a[i];
    if(i) a[i] += a[i-1];
  }

  ll ans = INF;
  rep(i, n-1){
    chmin(ans, abs(a[n-1] - a[i]*2));
  }
  cout << ans << endl;
  return 0;
}

/*
9
2-7...7-2
6-3...3-6
*/