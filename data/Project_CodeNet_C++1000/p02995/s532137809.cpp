#include <bits/stdc++.h>

#define loop(s, e, i) for (int i=s; i<e; ++i)
#define print(s) cout << s << endl;
using namespace std;
using ll = long long;

/*
浮動小数点の入力
cout << fixed << setprecision(9) << endl;
*/

ll gcd(ll a, ll b) {
  if (a < b) {
    return gcd(b, a);
  }
  while(b != 0) {
    ll tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}

int main() {
  ll A, B, C, D;
  cin >> A >> B >> C >> D;

  // CかDで割り切れるものの数
  ll g = C*D/gcd(C, D);
  ll n1 = (A-1)/C + (A-1)/D - (A-1)/g;
  ll n2 = B/C + B/D - B/g;
  print(B-n2-(A-1-n1));
}