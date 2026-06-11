#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

void solve(){
  long long n, k, ans = 0, cnt = 0; cin >> n >> k;
  string s; cin >> s;
  for(int i = 0; i < n - 1; i++){
    if(s[i] == s[i + 1]) ans++;
  }
  for(int i = 1; i < n; i++){
    if(s[i] != s[i - 1]){
      cnt++;
      if(cnt % 2 == 0){
        ans += 2;
        if(cnt / 2 >= k) break;
      }
    }
  }
  if(cnt % 2 == 1) ans++;
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
