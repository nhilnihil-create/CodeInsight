#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n;
  cin >> n;
  double ans = double(n - n/2);
  ans /= double(n);
  //cout.precision(10);
  cout << ans << endl;

}