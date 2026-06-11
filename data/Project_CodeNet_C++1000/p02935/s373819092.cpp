#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int n;

  cin >> n;

  vector<double> v(n);

  rep(i, n) cin >> v.at(i);

  double ans = 0;

  sort(v.begin(), v.end());

  // ans = (v.at(0) + v.at(1))/2;
  // ans = (ans + v.at(n-1))/2;

  double hidari = 0, migi = 0;

  for (int i = 0; i < n-1; i++){
    hidari = v.at(i);
    migi = v.at(i + 1);
    v.at(i + 1) = (hidari + migi) / 2;
  }

  cout << v.at(n-1);
}
