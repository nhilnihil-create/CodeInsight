#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
int main() {
  string s, t;
  cin >> s >> t;
  int a, b;
  cin >> a >> b;
  string u;
  cin >> u;
  if (u == s)
    a--;
  else
    b--;
  cout << a << ' ' << b << endl;
}