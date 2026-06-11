#include<bits/stdc++.h>
using namespace std;
int main() {
  int a, ans, temp;
  cin >> a;
  temp = a % 1000;
  ans = 1000 - temp;
  if(temp == 0) cout << 0 << endl;
  else cout << ans << endl;
}