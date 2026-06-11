#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int t_turn = 0;
  int a_turn = 0;
  if(b >= c) t_turn = 1;
  else {
    if(c % b == 0) t_turn = c / b;
    else t_turn = (c / b) + 1;
  }
  if(d >= a) a_turn = 1;
  else {
    if(a % d == 0) a_turn = a / d;
    else a_turn = (a / d) + 1;
  }
  
  bool flag = false;
  if(t_turn <= a_turn) flag = true;
  
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}