#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  int ans[1000][1000] = {0};

  for (int i = 0; i < B; ++i)
  {
    for (int j = 0; j < A; ++j)
    {
      ans[i][j] = 1;
    }
  }
  for (int i = B; i < H; ++i)
  {
    for (int j = A; j < W; ++j)
    {
      ans[i][j] = 1;
    }
  }
  for(int i=0;i<H;++i){
    for (int j = 0;j<W;++j){
      cout << ans[i][j];
    }
    cout << "\n";
  }
}