#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG



int main() {
  string S, T;
  cin >> S >> T;
  //vector<ll> a(N);
  //vector<vector<int>> data(3, vector<int>(4));
  ll A, B;
  cin >> A >>B;

  string U;
  cin >> U;
  if(U == S) cout << A-1 << " " << B << endl;
  else cout << A << " " << B-1 << endl;

  return 0;
}
