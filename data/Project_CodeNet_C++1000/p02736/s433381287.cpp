#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){  
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a(n);
  bool one = false;
  rep(i,n) {
    a[i] = s[i] - '1';
    if(a[i] == 1) one = true;
  }
  if(!one) {
    rep(i,n) a[i] /= 2;
  }
  int m = 0;
  rep(i,n) {
    if(n-1 == (i | (n-1-i))) m += a[i]; 
  }
  if(one && (m % 2)) cout << 1 << endl;
  else if(one && !(m % 2)) cout << 0 << endl;
  else if(!one && (m % 2)) cout << 2 << endl;
  else cout << 0 << endl;
  return 0;
}
