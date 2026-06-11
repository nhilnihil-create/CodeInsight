#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

void swap(int *a, int *b) {
  int *tmp = a;
  a = b;
  b = tmp;
}

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  swap(x, y);
  swap(x, z);
  cout << x << " " << y << " " << z << endl;
}
