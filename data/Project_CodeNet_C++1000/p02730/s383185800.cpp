#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  bool flag = true;
  string A = S.substr(0, (N - 1) / 2);
  string A_ = A;
  reverse(A_.begin(), A_.end());
  if (A_ != A) flag = false;
  string B = S.substr((N + 1) / 2, (N - 1) / 2);
  string B_ = B;
  reverse(B_.begin(), B_.end());
  if (B_ != B) flag = false;
  string S_ = S;
  reverse(S_.begin(), S_.end());
  if (S_ != S) flag = false;
  if (flag == true) cout << "Yes" << endl;
  else cout << "No" << endl;
}