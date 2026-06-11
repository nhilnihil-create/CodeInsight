#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int h, n;
  cin >> h >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  ll sum = 0;
  rep(i, n) sum += a.at(i);
  bool flag = false;
  if(sum >= h) flag = true;
  
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
