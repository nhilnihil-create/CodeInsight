#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  while(1)
  {
    int H, W;
    cin >> H >> W;
    if(H == 0 && W == 0) break;

    for(int i = 0; i < H; i++)
    {
      for(int j = 0; j < W; j++)
      {
        cout << (i == 0 || i == H-1 || j == 0 || j == W-1 ? "#" : ".") << flush;
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}