#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int r = N % 2;
  int res = N / 2;
  
  if (r == 0) {
    cout << res << endl;
  } else {
    cout << res + 1 << endl;
  }
  return 0;
}
