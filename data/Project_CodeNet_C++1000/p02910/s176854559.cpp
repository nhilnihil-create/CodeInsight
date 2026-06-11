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
  rep(i,S.size()) {
    if (i%2==0 && S[i]=='L') {
      cout << "No" << endl;
      return 0;
    }
    else if (i%2!=0 && S[i]=='R') {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}