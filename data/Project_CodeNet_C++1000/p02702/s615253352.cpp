#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<int> arr(2019);
  int res = 0;
  for (char c : s) {
    vector<int> new_arr(2019);
    int x = c - 48;
    for (int i = 0; i < 2019; ++i) {
      int y = (i * 10 + x) % 2019;
      new_arr[y] += arr[i];
    }
    new_arr[x]++;
    res += new_arr[0];
    arr = new_arr;
  }
  cout << res << endl;
}
