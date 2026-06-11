#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
const ll mod = 1e9+7;
const ll INF = 1e18;
#define All(a) (a).begin(),(a).end()
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  ll n;
  cin >> n;
  vector<string> a(n); 
  rep(i,n) {
    string s;
    cin >> s;
    sort(All(s));
    a[i] = s;
  }
  sort(All(a));
  ll ans = 0;
  ll len = 1;
  rep(i,n-1) {
    if (a[i] == a[i+1]) {
      ++len;
    }
    else {
      ans += len*(len-1)/2;
      len = 1;
    }
  }
  ans += len*(len-1)/2;
  cout << ans << '\n';

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}