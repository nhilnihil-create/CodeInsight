#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<ll> A(n, 0);
  vector<ll> B(m, 0);
  rep(i, n) cin >> A.at(i);
  rep(i, m) cin >> B.at(i);
  vector<ll> culsumA(n+1, 0);
  vector<ll> culsumB(m+1, 0);
  reps(i, 1, n+1) culsumA.at(i) = culsumA.at(i-1) + A.at(i-1);
  reps(i, 1, m+1) culsumB.at(i) = culsumB.at(i-1) + B.at(i-1);
  int j = 0;
  while(j <= m && culsumB.at(j) <= k) j++;
  j--;
  int ans = 0;
  for(int i = 0; i < n+1; i++) {
    while(j > 0 && culsumB.at(j) + culsumA.at(i) > k) j--;
    if (culsumB.at(j) + culsumA.at(i) <= k) {
      ans = max(ans, j+i);
    }
  }
  cout << ans << endl;
  
  
  return 0;
}