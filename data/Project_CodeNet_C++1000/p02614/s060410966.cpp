#include<bits/stdc++.h>
using namespace std;

int main() {
  int n,m,k;
  cin >> n >> m >> k;
  vector<string> v(n);
  for(int i = 0;i<n;i++)
  {
    cin >> v[i];
 //   cout << v[i] << endl;
  }
  int result = 0;

  for(int mask_i = 0; mask_i < (1<<n) ; mask_i++)
  {
    for(int mask_j = 0;mask_j < (1 << m);mask_j++)
    {
      int black = 0;
      for(int i = 0;i < n;i++)
      {
        for(int j = 0;j<m;j++)
        {
          if(((mask_i >> i) & 1) == 0 && ((mask_j >> j) & 1) == 0 && v[i][j] == '#' )
            black++;
        }
      }
      if(black == k) result++;
    }
  }
  cout << result << endl;
  return 0;
}
