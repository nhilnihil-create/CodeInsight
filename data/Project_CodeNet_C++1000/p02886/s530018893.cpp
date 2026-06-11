#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> takoyaki(n);
  int ans = 0;
  for (int i = 0; i < n; i++) cin >> takoyaki[i];

  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
        ans += takoyaki[i] * takoyaki[j];
    }
  }

  cout << ans;
}