#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long h, w, t;
  cin >> h >> w;
  t = h*w;
  if (h == 1 || w == 1)
  {
    cout << 1 << endl;
  }else if (t%2 == 0)
  {
    cout << t/2 << endl;
  }else
  {
    cout << t/2+1 << endl;
  }
  
  
  
  return 0;
  

}
