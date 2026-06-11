#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  return b != 0 ? gcd(b, a % b) : a;
}

int main(){
  ll A, B;
  cin >> A >> B;
  cout << A * B / gcd(A, B) << endl;
}
