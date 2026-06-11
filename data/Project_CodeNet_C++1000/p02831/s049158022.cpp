#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);
ll gcd(int x, int y){
  int r;
  while(true){
    r = x%y;
    if(r == 0){
      return y;
    }
    x = y;
    y = r;
  }
}
int main() {
  ll a,b;
  cin >> a >> b;
  ll c = gcd(a,b);
  ll ans = a*b/c;
  cout<< ans << endl;
}