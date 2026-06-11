#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int x;
bool eval(int left, int right) {
    return (left <= x && x < right);
}

int main() {
  cin >> x;
  for (int left = 400; left <= 1800; left += 200) {
    int right = left + 200;
    if (eval(left, right)) {
      cout << (2000 - left) / 200 << endl;
      return 0;
    }
  }
  return 0;
}