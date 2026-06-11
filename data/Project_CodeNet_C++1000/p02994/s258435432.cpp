#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, l;
  cin >> n >> l;
  int total = n * (l - 1) + n * (n + 1) / 2;
  int eat;
  if (l + n - 1 < 0) {  // 最大を足しても負なので、最大を食べる
    eat = l + n - 1;
  } else if (l >= 0) {  // 何も食べなくても正なので、最小を食べる
    eat = l;
  } else {  // ZEROになるように食べる
    eat = 0;
  }

  cout << total - eat << endl;
  return 0;
}
