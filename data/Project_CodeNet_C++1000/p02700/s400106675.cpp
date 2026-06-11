#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define ll long long
using namespace std;


int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  string ans = "Yes";
  
  while(a >= 0 && b >= 0){
    c -= b;
    if(c <= 0) break;
    a -= d;
    if(a <= 0) ans = "No";
  }
   
  cout << ans << endl;
  return 0;
}
