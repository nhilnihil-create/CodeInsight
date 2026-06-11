#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  double L; cin >>L;
  cout <<fixed;
  cout <<setprecision(12) <<pow(L/3.0,3) <<endl;
  return 0;
}
