#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i )

using namespace std;

int main(){
  int x; cin >> x;
  if(x % 2 == 0) cout << x/2 -1 << endl;
  else cout << x/2 << endl;
  return 0;
}