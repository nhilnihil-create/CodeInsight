#include <bits/stdc++.h>
using namespace std;

const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)


int main() {
  int n,d;
  cin >> n >> d;
  vector<vector<int>> vec(n, vector<int>(d, 0));
  REP(i,n) REP(j,d) cin >> vec[i][j];
  double tmp = 0;
  int ans = 0;
  REP(i,n) FOR(j,i+1,n){
    tmp = 0;
    REP(k,d) tmp += pow((vec[i][k] - vec[j][k]),2.0);    
    tmp = sqrt(tmp);
    // cout << tmp << " " << (int)tmp  << " " << i << j << endl;
    if (tmp - (int)tmp == 0) ans +=1; 
  }

  cout << ans << endl;
}