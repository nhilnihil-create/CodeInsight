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
  int N;
  cin >> N;
  string S;
  cin >> S;
  int ans = 1;
  char temp = S[0];
  for (int i = 1; i < N; ++i) {
    if (temp != S[i]) ++ans;
    temp = S[i];
  }
  cout << ans << endl;
  return 0;
}