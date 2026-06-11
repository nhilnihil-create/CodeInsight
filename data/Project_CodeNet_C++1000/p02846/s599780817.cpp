#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {

  long long T1,T2,A1,A2,B1,B2;
  cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

  long long d1 = (A1-B1)*T1,d2 = (A2-B2)*T2;

  if(d1 > 0) {
    d1 *= -1;
    d2 *= -1;
  }

  if(d1+d2 < 0) cout << 0 << endl;
  else if(d1+d2 == 0) cout << "infinity" << endl;
  else {
    long long n = -d1 / (d1+d2);
    long long r = -d1 % (d1+d2);
    if(r == 0) cout << n*2 << endl;
    else cout << n*2+1 << endl;
  }
}



