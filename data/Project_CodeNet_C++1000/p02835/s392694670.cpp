#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
  int a,b,c;
  string ans;
  cin >> a >> b >> c;
  if(a+b+c>=22) ans="bust";
  else ans = "win";
  cout << ans << endl;
  
  return 0;
}