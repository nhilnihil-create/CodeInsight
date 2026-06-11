#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, h, a, count;
  cin >> n >> h;
  count = 0;
  for (int i=0; i<n; i++) {
    cin >> a;
    if (a>=h) count++;
  }
  cout << count << endl;
}