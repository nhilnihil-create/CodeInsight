#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,L;
  cin >> N >> L;
  int count = 1000;
  int ans = 0;
  for (int i = L; i < L + N; i++) {
    ans += i;
    if (abs(i) < abs(count))
      count = i;
  }
  cout << ans - count << endl;
}

