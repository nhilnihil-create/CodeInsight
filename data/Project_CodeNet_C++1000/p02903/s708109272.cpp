#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (i < B)
      {
        cout << (j < A ? 1 : 0);
      }
      else
      {
        cout << (j < A ? 0 : 1);
      }
    }
    cout << endl;
  }
}