#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  string a, b;
  cin >> a >> b;
  int num_a = stoi(a); //stoi(''''string''')
  int num_b = stoi(b);
  string cmp_a;
  rep(i, num_b) cmp_a += a;
  string cmp_b;
  rep(i, num_a) cmp_b += b;
  if(cmp_a <= cmp_b) cout << cmp_a << endl;
  else cout << cmp_b << endl;
  return 0;
}
