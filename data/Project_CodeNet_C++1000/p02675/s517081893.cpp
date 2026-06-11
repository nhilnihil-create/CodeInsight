#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  int c = n%10;
  if (c == 3){
    cout << "bon" << endl;
  }else if (c == 0 || c == 1 || c == 6 || c == 8) {
    cout << "pon" << endl;
  }else {
    cout << "hon" << endl;
  }
  return 0;
}
