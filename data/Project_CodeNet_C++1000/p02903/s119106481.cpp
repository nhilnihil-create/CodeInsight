#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t H, W, A, B;
  cin >> H >> W >> A >> B;
  for (int h = 0; h < H; h++)
  {
    for (int w = 0; w < W; w++)
    {
      if (h < B)
        cout << ((w < A) ? 0 : 1);
      else
        cout << ((w < A) ? 1 : 0);
    }
    cout << endl;
  }
}