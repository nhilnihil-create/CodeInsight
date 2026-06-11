#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string S;
  cin >> S;
  if (S[1] == 'B') cout << "ARC" << endl;
  else cout << "ABC" << endl;
  return 0;
}