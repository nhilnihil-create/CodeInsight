#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, ans = 0;
  cin >> n >> k;
  vector<int> d(k);
  vector<vector<int>> a(k,vector<int>(n,0));
  vector<bool> c(n+1, false);
  for (int i = 0; i < k; i++)
  {
    cin >> d[i];
    for (int j = 0; j < d[i]; j++)
    {
      cin >> a[i][j];
      c[a[i][j]]= true;
    }
    
  }
  for (int i = 1; i < n+1; i++)
  {
    if (c[i] == false)
    {
      ans++;
    }
    
  }
  cout << ans << endl;
  
  return 0;
}
