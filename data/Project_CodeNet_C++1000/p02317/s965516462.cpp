#include <bits/stdc++.h>
#define LLINF 1LL << 60
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int main()
{
  int n; cin >> n;
  vector<ll> a(n);
  vector<ll> dp(n,LLINF);
  REP(i,n) cin >> a[i];
  REP(i,n) *lower_bound(dp.begin(),dp.end(),a[i]) = a[i];
  cout << lower_bound(dp.begin(),dp.end(),LLINF)-dp.begin() << endl;
  return 0;
}