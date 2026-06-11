#include <bits/stdc++.h>
using namespace std;
int main(){
  long long a,b,c,d;	cin >> a >> b >> c >> d;
  long long numc=b/c-(a-1)/c;
  long long numd=b/d-(a-1)/d;
  long long numcd=b/(c/__gcd(c,d)*d)-(a-1)/(c/__gcd(c,d)*d);
  cout << b-(a-1)-(numc+numd-numcd);
}