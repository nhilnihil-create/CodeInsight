#include <iostream>
#include <vector>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> ans(n);
  int k;
  rep(i,n) {
    cin >> k;
    k--;
    ans[k] = i;
  }
  rep(i,n-1) {
    cout << ans[i] + 1 << " ";
  }
  cout << ans[n-1] + 1 << endl;
  return 0;
}