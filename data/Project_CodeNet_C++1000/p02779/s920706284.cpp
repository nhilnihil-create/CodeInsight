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
  map<string,int> A;
  rep(i,N) {
    string c;
    cin >> c;
    if (A[c] != 0) {
      cout << "NO" << endl;
      return 0;
    }
    else {
      A[c] = 1;
    }
  }
  cout << "YES" << endl;
  return 0;
}