#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  bool ans = true;
  if(a==b && b==c) ans = false;
  if(a!=b && b!=c && c!=a) ans = false;
  cout << (ans?"Yes":"No") << endl;
  return 0;
}
