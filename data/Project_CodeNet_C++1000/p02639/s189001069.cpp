#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> vec(5);
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    cin >> vec.at(i);
    if (vec.at(i) == 0) {
      cout << i + 1;
    }
  }
}