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
  int K, X;
  cin >> K >> X;
  for (int i = X-K+1; i <= X+K-1; ++i) {
    cout << i;
    if (i != X+K-1) cout << " ";
    else cout << endl;
  }
  return 0;
}