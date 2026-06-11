#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  int a, b;
  cin >> a >> b;
  int n = gcd(a, b);
  if(n == 1) cout << (ll)a*b << endl;
  else {
    int s = a / n;
    int t = b / n;
    cout << n*s*t << endl;
  }
  return 0;
}