#include <iostream>
#include <algorithm>
using namespace std;

int rec(int n, int p, int s) {
  if(s < 0) return 0;
  if(n == 0) return s == 0;
  int res = 0;
  for(; p <= 9; ++p) {
    res += rec(n-1, p+1, s-p);
  }
  return res;
}

int main() {
  int n, s;
  while(cin >> n >> s && (n|s)) {
    cout << rec(n,0,s) << endl;
  }
  return 0;
}