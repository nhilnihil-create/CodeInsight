#include <bits/stdc++.h>
#define r(i, n) for (int i=1;i<n+1;i++)
using namespace std;
int main() {
  int m,d,a=0;
  cin >> m >> d;
  r(i, m) {
    r(j, d) {
      if((j%10)>=2 && (j/10)>=2 && (j%10)*(j/10)==i) a++;
    }
  }
  cout << a <<endl;
  return 0;
}