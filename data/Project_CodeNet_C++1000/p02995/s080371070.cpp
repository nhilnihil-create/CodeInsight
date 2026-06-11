#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

ll GCD(ll x,ll y){
  if(y == 0) return x;
  return GCD(y,x%y);
}

int main() {
  ll a,b,c,d,e,f;
  cin >> a >> b >> c >> d;
  f = c*d/GCD(c,d);
  e = b/c-a/c+b/d-a/d-(b/f-a/f);
  if(a%c == 0) e++;
  if(a%d == 0) e++;
  if(a%f == 0) e--;
  cout << b-a+1-e << endl;
}