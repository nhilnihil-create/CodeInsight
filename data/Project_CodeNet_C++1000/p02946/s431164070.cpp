#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int k , x;
  cin >> k >> x;
  int max = x + k - 1;
  int min = x - k + 1;

  if (max <= 1000000 && min >= -1000000) {
    for (int i = min; i <= max; i++) cout << i << " ";
  }

  else if (max >= 1000000 && min >= -1000000) {
    for (int i = min; i <=1000000; i++) cout << i << " ";
  }

  else if (max <= 1000000 && min <= -1000000) {
    for (int i = -1000000; i <= max; i++) cout << i << " ";
  }

  else {
    for (int i = -1000000; i <= 1000000; i++) cout << i << " ";
  }
}