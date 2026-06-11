#include <bits/stdc++.h>
using namespace std;

int main() {
  int H1, M1, H2, M2, K, ans;
  cin >> H1 >> M1 >> H2 >> M2 >> K;
  ans = (H2-H1)*60+(M2-M1)-K;
  if(ans<0) ans=24*60+ans;
  cout << ans << endl;
}