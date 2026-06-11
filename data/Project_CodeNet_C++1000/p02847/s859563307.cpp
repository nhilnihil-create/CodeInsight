#include <bits/stdc++.h>
using namespace std;

const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)

int main() {
  string a,b;
  cin >> a;
  int ans = 7;
  vector<string> vec = {"MON","TUE","WED","THU","FRI","SAT"};
  REP(i,6)if(vec[i] == a) ans = 6-i;
  cout << ans << endl;
}