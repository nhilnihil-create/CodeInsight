#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  string ans = "No";
  if (N <= 9) {
    ans = "Yes";
  }
  
  for (int i = 2; i <= 9; i++) {
    if (N % i == 0 && N / i <= 9) {
      ans = "Yes";
    }
  }
  
  cout << ans << endl;
}
