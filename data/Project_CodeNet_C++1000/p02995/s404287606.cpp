#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
 long long a,b,c,d;
 cin >> a >> b >> c >> d;
 
 long long x;
 x = b - a + 1;
 
 long long divall = b/c + b/d - b/lcm(c,d);
 long long divpart = (a-1)/c +(a-1)/d - (a-1)/lcm(c,d);
 
 
 

 cout << x - (divall-divpart);


  }