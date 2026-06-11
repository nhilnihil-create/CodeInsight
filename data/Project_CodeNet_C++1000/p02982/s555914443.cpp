#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;


int main()
{
  int N, D;
  cin >> N >> D;
  vector<vector<int>> vec;
  REP(i, N) {
    vector<int> tmp(D);
    REP(j, D) {
      cin >> tmp[j];
    }
    vec.push_back(tmp);
  }  
  int res = 0;
  REP(i, N) {
    for (int j = i+1; j < N; j++) {
      if (i == j) {
        continue;
      }
      double ans = 0;
      REP(k, D) {
        int b = abs(vec[i][k] - vec[j][k]);
        ans += b*b;
      }
      ans = sqrt(ans);
      if(abs(ans - (int)ans)>0) {
        continue;
      }
      res++;
    }
  }
  cout << res << endl;
  return 0;
}