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
  int n; cin >> n;
  vector<int> m(n); REP(i,n) m[i] = INF;
  vector<int> p(n); REP(i,n) cin >> p[i];
  int ans = 1;
  m[0] = p[0];
  FOR(i,1,n){
    m[i] = min(p[i],m[i-1]);
    if(p[i] == m[i])
      ans++;
  }
  cout << ans << endl;
}