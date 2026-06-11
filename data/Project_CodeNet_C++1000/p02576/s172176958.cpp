#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
#define F first
#define S second
const ll mod = 1e9 + 7;
const ll INF = 922337203685477;
#define pb push_back
#define deb(x) cout << '>' << #x << ':' << x << endl;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define maxN 200007
using namespace std;
int main() {
  fastio;
  ll n = 0, x = 0, t = 0;
  cin >> n >> x >> t;
  ll q = n / x;
  ll r = n % x;
  if (r)
    ++q;
  cout << q*t;
}