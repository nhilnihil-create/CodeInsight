#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main() {
  long double a, b,c;
  cin >> a >> b >> c;
  long double eps = 1.0E-14;
  if(sqrt(a) + sqrt(b) + eps < sqrt(c)) puts("Yes");
  else puts("No");
  return 0;
}