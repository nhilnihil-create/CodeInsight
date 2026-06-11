#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;	cin >> n;
  long long m=1e12;
  for(int a=1;a<=sqrt(n);a++){
    long long b=n/a;
    if(a*b==n)	m=min(a+b-2,m);
  }
  cout << m;
}