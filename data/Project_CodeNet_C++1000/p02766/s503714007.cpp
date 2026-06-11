#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n , k;
  cin >> n >> k;
  int ans = 0;
  while(n > k){
    n /= k;
    ans++;
    // cout << n << " ";
  }
  // cout << endl;
  if(n != k) cout << ++ans << endl;
  else cout << ans + 2 << endl;
  return 0;
}