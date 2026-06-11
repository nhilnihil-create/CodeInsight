#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int digit(int n) {
  int d = 0;
  while(n > 0) {
    d++;
    n /= 10;
  }
  return d;
}

int main(){
  int n;
  cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; i++) if(digit(i) % 2) ans++;
  cout << ans << endl; 
  return 0;
}
