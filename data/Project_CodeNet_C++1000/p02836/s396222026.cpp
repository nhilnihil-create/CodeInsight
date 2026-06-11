#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string S;
  cin >> S;
  int cnt = 0;
  rep(i,S.size()/2) {
    if (S[i] != S[S.size()-1-i]) ++cnt;
  }
  cout << cnt << endl;
  return 0;
}