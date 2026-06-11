#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)

int main()
{
  long long a,v,b,w;
  cin >> a >> v >> b >> w;
  long long t;
  cin >> t;

  long long dis = abs(b - a);
  long long rel = v - w;
  if(rel > 0)
  {
    bool ans = ((dis - 1) / rel < t);
    cout << (ans ? "YES" : "NO") << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  return 0;
}