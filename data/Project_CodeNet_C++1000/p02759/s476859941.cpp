#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, ans;
  cin >> n ;
  if (n%2 == 0){
    ans = n/2;
  } else {
    ans =n/2 + 1;
  }
  cout << ans << endl;
  return 0;
}