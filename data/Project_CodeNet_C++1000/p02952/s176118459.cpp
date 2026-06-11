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
  string tmp;
  int ans = 0;
  FOR(i,1,n+1) {
    tmp = to_string(i);
    if (tmp.size()%2!=0) ans +=1; 
  }
  cout << ans << endl;
  
}