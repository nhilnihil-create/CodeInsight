#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int gcd(int a, int b) {
  int d=a;
  if (b!=0) {
    d=gcd(b,a%b);
  }
  return d;
}

int main() {
  ll A,B,C,D;
  cin >> A >> B >> C >> D;
  ll m=B/C-(A-1)/C;
  ll n=B/D-(A-1)/D;
  ll mn=B/(C*D/gcd(C,D))-(A-1)/(C*D/gcd(C,D));
  cout << B-A+1-(m+n-mn) << endl;
}