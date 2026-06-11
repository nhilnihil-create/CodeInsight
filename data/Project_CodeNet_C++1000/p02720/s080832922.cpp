#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  cin >> k;

  queue<int64_t> lunluns;
  for (int i = 1; i <= 9;  ++i) lunluns.push(i);
  for (int i = 0; i < k-1; ++i) {
    int64_t x = lunluns.front();
    lunluns.pop();

    int64_t n = x * 10 + x % 10;
    if (x % 10 != 0) lunluns.push(n-1);
    lunluns.push(n);
    if (x % 10 != 9) lunluns.push(n+1);
  }
  cout << lunluns.front() << endl;
}
