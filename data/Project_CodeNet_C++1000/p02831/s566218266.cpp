#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

static const int MAX = 200000;


int main() {
  int a,b;
  cin >> a >> b;
  ll num =  (ll)a * b / gcd(a, b);
  cout << num << endl;
}
