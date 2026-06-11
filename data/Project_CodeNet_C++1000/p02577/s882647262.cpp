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
  string s;
  cin >> s;
  ll n = s.length();
  ll sum = 0;
  for (ll i = 0; i < n; ++i)
    sum += (s[i] - '0');
  if (sum % 9)
    cout << "No";
  else
    cout << "Yes";
}