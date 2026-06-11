#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
  
  int h, w, n;
  cin >> h >> w >> n;
  rep(i, max(h, w) + 1) {
    if(max(h, w) * i >= n) {
      cout << i << endl;
      break;
    }
  }

    return 0;
}