#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  long double a,b,c; cin >>a >>b >>c;
  long double e = 1.0e-14;
  if(sqrt(a)+sqrt(b)+e<sqrt(c)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
