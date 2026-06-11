#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n, 0);
  REP(i, n) cin >> a[i];
  k = min(k, 100);
  REP(j, k)
  {
    vector<int> b(n, 0);
    REP(i, n)
    {
      int l,r;
      l = max(0, i - a[i]);
      r = min(n - 1, i + a[i]);
      b[l]++;
      if(r + 1 < n) b[r+1]--;
    }
    REP(i, n-1)
    {
      b[i+1] += b[i];
    }
    REP(i, n)
    {
      a[i] = b[i];
    }
  }
  REP(i, n)
    cout << a[i] << " ";
  
  return 0;
}