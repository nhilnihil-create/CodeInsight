#include <iostream>
#include <vector>
#include <climits>
#define eol '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, v, mi = INT_MAX, max_df = INT_MIN;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> v;
    max_df = max(max_df, v - mi);
    mi = min(mi, v);
  }
  
  cout << max_df << eol;
  
  return 0;
}