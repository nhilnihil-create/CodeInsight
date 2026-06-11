#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main()
{
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  int i = 0;
  while(true) {
    //cout << a << ':' << b << ':' << c << ':' << i << endl;
    if(i > n) {
      cout << "No" << endl;
      break;
    }
    else if(a >= b) {
      b *= 2;
      i++;
      continue;
    }
    else if(b >= c) {
      c *= 2;
      i++;
      continue;
    }
    cout << "Yes" << endl;
    break;
  }
  return 0;
}
