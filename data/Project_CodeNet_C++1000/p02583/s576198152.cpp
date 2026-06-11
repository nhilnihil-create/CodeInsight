#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <vector>

#define rep(i, n) for (auto i = 0; i < (n); i++)
#define MOD 1e9 + 7
typedef long long ll;

using namespace std;

int main() {
  int n;
  cin >> n;
  int l[n];
  rep(i, n) {
    cin >> l[i];
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      for (int k = j+1; k < n; k++) {
        if (l[i] != l[j] && l[i] != l[k] && l[j] != l[k] &&
            (l[i] + l[j] > l[k]) && (l[i] + l[k] > l[j]) && (l[j] + l[k] > l[i])) {
          ans++;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}

