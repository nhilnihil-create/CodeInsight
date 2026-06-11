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
map<string, int> m;
int main() {
  m["SUN"] = 0;
  m["MON"] = 1;
  m["TUE"] = 2;
  m["WED"] = 3;
  m["THU"] = 4;
  m["FRI"] = 5;
  m["SAT"] = 6;
  string s;
  cin >> s;
  cout << ((7 - m[s] + 7) % 7 == 0 ? 7 : (7 - m[s] + 7) % 7) << endl;
}