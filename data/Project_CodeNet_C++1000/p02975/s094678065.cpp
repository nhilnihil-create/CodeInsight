#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;

int main() {
  ll n; cin >> n;
  Vl a(n);
  rep(i, 0, n) cin >> a[i];

  ll ans = 0;
  rep(i, 0, n) ans ^= a[i];

  if(ans == 0) puts("Yes");
  else puts("No");


  return 0;
}
