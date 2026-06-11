#include <bits/stdc++.h>
using namespace std;
const int days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};
const string s[] = {"Wednesday", "Thursday", "Friday", "Saturday",
                    "Sunday",    "Monday",   "Tuesday"};
int main() {
  int m, d;
  while (cin >> m >> d, m | d) {
    int sum = d;
    for (int i = 0; i < m - 1; i++) {
      sum += days[i];
    }
    cout << s[sum % 7] << endl;
  }
}

