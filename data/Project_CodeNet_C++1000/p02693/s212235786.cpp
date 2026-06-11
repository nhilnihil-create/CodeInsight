#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
  int k, a, b;
  cin >> k >> a >> b;
  if(a % k == 0 || b % k == 0) cout << "OK" <<endl;
  else if(a == b) cout << "NG" << endl;
  else if(b - a >= k) cout  << "OK" << endl;
  else if(a % k >= b % k) cout << "OK" <<endl;
  else cout << "NG" <<endl;
}