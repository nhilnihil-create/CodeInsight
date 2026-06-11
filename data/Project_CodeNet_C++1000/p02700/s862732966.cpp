#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int e = (a + (d - 1)) / d;
  int f = (c + (b - 1)) / b;
  e < f ? cout << "No" : cout << "Yes";
}
