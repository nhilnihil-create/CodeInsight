#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
  int n;
  while(cin >> n && n) {
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for(int i = 1; i < n; ++i) {
      a[i] += a[i-1];
    }
    a.insert(a.begin(), 0);
    int res = INT_MIN;
    for(int i = 0; i < n; ++i) {
      for(int j = i+1; j <= n; ++j) {
	int tmp = a[j]-a[i];
	res = max(res, tmp);
      }
    }
    cout << res << endl;
  }
  return 0;
}