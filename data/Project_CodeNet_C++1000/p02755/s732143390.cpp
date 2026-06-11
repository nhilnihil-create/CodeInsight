#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
#define _GLIBCXX_DEBUG

int main() {
  int a, b; cin >> a >> b;
  int x_a = (a*25 +1) /2;
  int x_b = b*10;

  if(x_a > x_b){
    if(x_a/10 == b) cout << x_a << endl;
    else cout << -1 << endl;
  }
  else{
    if(x_b*8/100 == a) cout << x_b << endl;
    else cout << -1 << endl;
  }
}
