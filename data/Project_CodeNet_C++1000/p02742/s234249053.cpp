#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  long long h,w;

  cin >> h >> w;

  long long val = h*w;

  if(h==1 || w==1)
  cout << 1;

  else if(val %2 == 0)
  cout << val/2;
  else
  {
    cout << val/2+1;
  }
  


}