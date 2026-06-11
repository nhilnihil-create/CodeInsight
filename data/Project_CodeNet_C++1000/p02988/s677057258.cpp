#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {

  int a;
  cin >> a;
  
  vector<int> t(a);
  rep(i,a) cin >> t[i];
  int ans = 0;
  
  rep(i,a-2) {
    if(t[i] < t[i+1] && t[i+1] < t[i+2]) ans += 1;
    else if(t[i] > t[i+1] && t[i+1] > t[i+2]) ans += 1;
  }
  
  cout << ans << endl;
  
  
  
}
