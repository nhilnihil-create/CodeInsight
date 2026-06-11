#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> H(N, vector<int>(N, -1));
  for (int i = 0; i < N; i++)
  {
    int A;
    cin >> A;
    while (A--)
    {
      int x, y;
      cin >> x >> y;
      --x;
      H[i][x] = y;
    }  
  }
  
  int ans = 0;
  for (int bit = 0; bit < (1 << N); bit++)
  {
    int temp = 0;
    vector<bool> x(N);
    for (int i = 0; i < N; i++)
    {
      if (bit & (1 << i))
      {
        x[i] = true;
        temp++;
      }
      
    }
    
    bool honest = true;
    for (int i = 0; i < N; i++)
    {
      if (!x[i])
      {
        continue;
      }
      
      for (int j = 0; j < N; j++)
      {
        if (H[i][j] == -1)
        {
          continue;
        }
        if ((H[i][j] && !x[j]) || (!H[i][j] && x[j]))
        {
          honest = false;
          break;
        }
        
      }
      if (!honest)
      {
        break;
      }
      
    }
    if (honest)
    {
      ans = max(temp, ans);
    }
    
  }
  cout << ans << endl;
  return 0;
}
