#include <bits/stdc++.h>
#define ll long long
#define pb(x) push_back((x))
#define line() cerr << "DEBUG @" << __LINE__ << endl;
#define debug(x) \
  cerr << "DEBUG @" << __LINE__ << " -> " << #x << " = " << x << endl;
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll d, t, s;
  cin >> d >> t >> s;
  cout << ((d <= t * s) ? "Yes" : "No") << "\n";
}
