#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int X,Y; cin >>X >>Y;
  string ans="No";
  rep_eq(i,0,X) {
    int j=X-i;
    if (i*2+j*4==Y) {
      ans="Yes";
      break;
    }
  }
  cout <<ans <<endl;
  return 0;
}
