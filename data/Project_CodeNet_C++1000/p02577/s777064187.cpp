#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  long long sum = 0;
  for (auto n : s) {
    sum += (n-'0');
  }
  if (sum % 9 == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
