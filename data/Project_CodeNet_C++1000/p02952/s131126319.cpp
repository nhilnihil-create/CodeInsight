#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n;
  cin >> n;
  
  int ans;
  
  if (n < 10) ans = n;
  else if(n < 100) ans = 9;
  else if(n < 1000) ans = (n / 100 - 1) * 100 + n % 100 + 1 + 9;
  else if(n < 10000) ans = 909;
  else if(n < 100000) ans = (n / 10000 - 1) * 10000 + n % 10000 + 1 + 909;
  else ans = 90909;
  
  cout << ans << endl;
  
}