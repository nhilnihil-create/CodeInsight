#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll A,B;
  cin >> A >> B;
  cout << A*B/__gcd(A,B);
}