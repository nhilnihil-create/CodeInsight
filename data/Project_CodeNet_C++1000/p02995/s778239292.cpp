#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  return b!=0 ? gcd(b, a % b) : a;
}

ll a, b, c, d, cnt_c, cnt_d, cnt_cd;

int main(){
  cin >> a >> b >> c >> d;
  cnt_c = b/c - (a-1)/c;
  cnt_d = b/d - (a-1)/d;
  cnt_cd = b/((c*d)/gcd(c, d)) - (a-1)/((c*d)/gcd(c, d));
  cout << (b-a+1) - (cnt_c + cnt_d - cnt_cd) << endl;
}