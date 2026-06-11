#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1000010;
 
char s[N];
int n, a[N], b[N];
 
int main() {
  scanf("%d %s", &n, s + 1); --n;
  bool isOne = 0;
  for (int i = 1; i <= n; ++i) {
    a[i] = abs(s[i] - s[i + 1]);
    if (a[i] == 1) isOne = 1;
  }
  // cout << brute() << " ";
  int fac = 1;
  if (!isOne) {
    for (int i = 1; i <= n; ++i) a[i] >>= 1;
    fac = 2;
  } 
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
  	if( ((n-1) | (i-1)) == (n-1) ) {
  		sum += (a[i] & 1), sum &= 1;
  	}
  }
  cout << sum * fac << '\n';
  return 0;
}
 