#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int H, W;
  cin >> H >> W;

  if (H == 1 || W == 1) {
    cout << 1 << endl;
  } else {
    cout << (H * W + 1) / 2 << endl;
  }
}
