#include <bits/stdc++.h>
using namespace std;

long long X,Y;long long base=1000000007LL;

long long kaijo(long long a) {
  if (a==0) return 1LL;
  else {
    return a*kaijo(a-1)%base;
  }
}

long long ruijo(long long a,long long b) {
  if (b==0LL) return 1LL;
  else {
    if (b%2==0) return (ruijo(a,b/2)*ruijo(a,b/2))%base;
    else return (a*ruijo(a,b-1))%base;
  }
}

int main() {
  cin >> X >> Y;
  if ((X+Y)%3LL!=0LL || Y>2*X || X>2*Y) cout << 0 << endl;
  else {
    long long k=(X+Y)/3LL;
    long long x=(2*Y-X)/3LL;
    long long y=(2*X-Y)/3LL;
    long long a=(kaijo(x)*kaijo(y))%base;
    cout << (kaijo(k)*ruijo(a,base-2LL))%base << endl;
  }
}