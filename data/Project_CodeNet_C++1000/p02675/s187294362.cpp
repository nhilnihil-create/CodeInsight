#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  int one = n % 10;
  if (one == 2 || one == 4 || one == 5 || one == 7 || one == 9) cout << "hon" << endl;
  else if (one == 3)  cout << "bon" << endl;
  else cout << "pon" << endl;
  return 0;
}