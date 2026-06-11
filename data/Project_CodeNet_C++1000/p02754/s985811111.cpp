#include <bits/stdc++.h>
using namespace std;
// (setq-default c-basic-offset 2)
int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  // Place A blue balls at the end of the row.
  // place B red balls at the end of the row
  // How many blue balls will there be among the first N balls in the row?

  // n = 8
  // a = 3
  // b = 4
  // BBB RRRR BBB
  //          ^

  // len_seq = 7
  // n = 8
  // n_seq = 1

  if (a == 0) {
    cout << "0" << endl;
    return 0;
  }
  long long len_seq = a + b;
  long long n_seq = n / len_seq;
  long long balls_left = n - len_seq * n_seq;
  long long ret = a * n_seq + (min(a, balls_left));

  cout << ret << endl;
  return 0;
}
