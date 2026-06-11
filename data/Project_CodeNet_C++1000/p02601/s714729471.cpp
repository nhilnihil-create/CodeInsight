#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  int k;
  string ans="No";

  cin >> a>>b>>c>>k;

  int x=0,y=0;

  while(a>=b) {
    b*=2;
    x++;
  }

  while(b>=c) {
    c*=2;
    y++;
  }

  if(x+y<=k) {
    ans="Yes";
  }

  cout <<ans<< endl;

  return 0;
}
