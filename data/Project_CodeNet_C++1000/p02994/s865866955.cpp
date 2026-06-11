#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#define ill long long
#define rep(i, a, b) for(ill i = (ill)(a); i < (ill)(b); i++)
#define fcout cout << fixed << setprecision(10)
using namespace std;

int main() {
  int n, l;
  cin >> n >> l;
  int sum = 0, mn = 10000;
  rep(i, 0, n) {
    sum += l+i;
    if(abs(l+i) < abs(mn)) mn = l+i;
  }
  cout << sum - mn << "\n";
  //cout << sum << " " << mn;
}