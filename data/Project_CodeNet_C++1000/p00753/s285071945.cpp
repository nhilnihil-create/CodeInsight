#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

#define ISEQ(c) (c).begin(), (c).end()
typedef long long ll;

int main() {
  vector<int> prime;
  int m = 123456*2;
  bool p[m+1];
  fill(p, p+m+1, false);
  for (int i = 2; i <= m; i++) {
    if (!p[i]) {
      prime.push_back(i);
      for (int j = i+i; j <= m; j += i) {
	p[j]  = true;
      }
    }
  }
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    int t =  lower_bound(ISEQ(prime), 2*n) - upper_bound(ISEQ(prime), n);
    cout << max(t, 1) << endl;
  }
}