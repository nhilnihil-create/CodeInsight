#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define ll long long
using namespace std;



int main() {
  int n;
  ll ans=0;
  cin >> n;
  for(int i=1; i<(n+1); i++){
    if(i%3 != 0 && i%5 != 0) ans += i;
  }
  cout << ans << endl;
  return 0;
}