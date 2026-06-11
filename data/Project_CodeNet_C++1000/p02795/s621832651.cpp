#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W,N;
  cin >> H >> W >> N;
  int big = max(H,W);
  cout << (N+big-1)/big << endl;
}
