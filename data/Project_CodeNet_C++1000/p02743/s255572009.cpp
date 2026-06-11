#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll a,b,c;
  cin >> a >> b >> c;
  if ((c-a-b) < 0) {
    cout << "No" << endl;
    return 0;
  }
  if ((c-a-b)*(c-a-b) > 4*a*b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
