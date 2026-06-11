#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll S;
  cin >> S;
  ll X1 = 0;
  ll Y1 = 0;
  ll X2 = 1000000000;
  ll Y2 = 1;
  cout << X1 << " " << Y1 << " " << X2 << " " << Y2;
  ll X3 = (X2 - (S % X2)) % X2;
  ll Y3 = ((S - 1) / X2) + 1;
  cout << " " << X3  << " " << Y3 << endl;
  return 0;
}