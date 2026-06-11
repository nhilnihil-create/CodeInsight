#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  set<int> snk;
  for(int i = 0; i < k; i++) {
    int d;
    cin >> d;
    for(int j = 0; j < d; j++) {
      int a;
      cin >> a;
      snk.insert(a);
    }
  }
  cout << (n - snk.size());
}