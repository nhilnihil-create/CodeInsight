#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  string s;
  cin >> s;
  int n = s.size();
  bool ok = true;
  int a = n / 2;
  rep(i,a) if(s[i] != s[n-1-i]) ok = false;
  int b = (n-1)/2;
  int c = b / 2;
  rep(i,c) if(s[i] != s[b-1-i]) ok = false;
  int d = (n+3)/2;
  int e = d / 2;
  for(int i = d; i < e; i++){
    if(s[i-1] != s[i+e-1]) ok = false;
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
