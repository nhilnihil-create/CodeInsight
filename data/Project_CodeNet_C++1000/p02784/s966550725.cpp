#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h,n;
  cin >> h >> n;
  int attack = 0;
  rep(i,0,n) {
    int a;
    cin >> a;
    attack += a;
  }
  if (attack >= h) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
