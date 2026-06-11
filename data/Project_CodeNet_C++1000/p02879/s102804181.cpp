#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  int a, b;
  cin >> a >> b;
  bool ok = true;
  if(a > 9) ok = false;
  if(b > 9) ok = false;
  if(ok) cout << a*b << endl;
  else cout << -1 << endl;
  return 0;
}