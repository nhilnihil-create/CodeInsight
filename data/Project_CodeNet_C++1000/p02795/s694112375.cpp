#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int h, w, n;
  cin >> h >> w >> n;
  int a = max(h,w);
  (n % a) ? cout << n / a + 1 : cout << n / a;
  cout << "\n";
return 0;
}