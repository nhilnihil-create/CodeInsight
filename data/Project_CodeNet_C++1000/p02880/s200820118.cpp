#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string ans = "No";
  cin >> N;
  
  if (1 <= N && N <= 4) ans = "Yes";
  if (5 <= N) {
    if (N%9 == 0 && N/9 < 10) ans = "Yes";
    if (N%8 == 0 && N/8 < 10) ans = "Yes";
    if (N%7 == 0 && N/7 < 10) ans = "Yes";
    if (N%6 == 0 && N/6 < 10) ans = "Yes";
    if (N%5 == 0 && N/5 < 10) ans = "Yes";
  }
  
  cout << ans << endl;;
}