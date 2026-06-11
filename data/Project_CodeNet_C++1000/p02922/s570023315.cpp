#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a,b;
  cin >> a >> b;
  int cnt = 1;
  int A = a;
  if (b == 1) cout << 0;
  else if(a == b) cout << 1;
  else if(1) {
    while(b > a) {
      a += A -1;
    cnt++;
  }
  cout << cnt << endl;  
  }
}
 