#include <bits/stdc++.h>
using namespace std;

bool ok[100];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    int d;
    cin >> d;
    for (int j = 0; j < d; ++j) {
      int a;
      cin >> a;
      ok[a - 1] = true;
    }
  }
  
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (!ok[i]) ++cnt;
  }
  cout << cnt << endl;
}