#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  ll X;
  cin >> X;
  ll m;
  for (ll i=1; i<1000; i++) {
    if (i*i*i*i>X) {
      m=i-1;
    }
  }
  ll A, B, fin=0;
  for (ll b=-m; b<=1000; b++) {
    for (ll a=b; a<=1000; a++) {
      if (a*a*a*a*a-b*b*b*b*b==X) {
        A=a;
        B=b;
        fin=1;
        break;
      }
    }
    if (fin==1) {break;}
  }
  cout << A << " " << B << endl;
}