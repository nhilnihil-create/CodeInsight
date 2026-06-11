#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define rep(i, n) for(ll i = 0;i < n;i++)
#define all(i) i.begin(), i.end()
template<class T, class U> bool cmax(T& a, U b) { if (a<b) {a = b; return true;} else return false; }
template<class T, class U> bool cmin(T& a, U b) { if (a>b) {a = b; return true;} else return false; }

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  ll cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (i < n-i) {
      cnt++;
    }
  }
  cout << cnt << endl;
}
