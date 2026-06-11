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
  int ans = 0;
  rep(i,N-2) {
    if (S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C') ++ans;
  }
  cout << ans << endl;
  return 0;
}