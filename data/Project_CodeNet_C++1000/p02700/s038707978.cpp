#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x = (c + (b - 1)) / b;
  int y = (a + (d - 1)) / d;
  cout << (y>=x?"Yes":"No") << endl;
  return 0;
}