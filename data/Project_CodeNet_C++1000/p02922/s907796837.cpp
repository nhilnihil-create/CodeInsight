#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;
  int sum = 1;
  int count = 0;
  while (true) {
    if(sum >= b) {
      break;
    }
    sum += a-1;
    count++;
  }
  cout << count << endl;
}