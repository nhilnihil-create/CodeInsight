#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> x(0);
  int q = -1, r;
  while(q != 0) {
    q = n / k;
    r = n % k;
    x.push_back(r);
    n = q;
  }
  cout << x.size() << endl;
}