#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  int a = max(h, w);
  cout << (n+a-1)/a << endl;
}