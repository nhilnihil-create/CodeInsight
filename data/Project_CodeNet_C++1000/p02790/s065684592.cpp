#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  string s, t;
  rep(i,b) s += a+'0';
  rep(i,a) t += b+'0';
  cout << min(s,t) << endl;
  return 0;  
}