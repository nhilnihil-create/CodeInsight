#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if(a<b+c) cout << c-a+b << endl;
  else cout << 0 << endl;
}