#include <bits/stdc++.h>
using namespace std;

const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)



int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  REP(i,n)cin >> vec[i];
  int c = 0;
  string ans = "YES";
  REP(i,n) if (vec[i] != i+1) c+=1; 
  if (c > 2) ans = "NO";
  cout << ans << endl;
}