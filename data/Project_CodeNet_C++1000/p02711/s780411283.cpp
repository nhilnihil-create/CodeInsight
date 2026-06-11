#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  string ans="No";
  cin >> N;
  if(N%10==7) ans = "Yes";
  else if((N/10)%10==7) ans = "Yes";
  else if((N/100)%10==7) ans = "Yes";

  cout << ans << endl;
  
  return 0;
}