#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  int n;
  const int max_n = 1e5;
  string s[max_n + 1];

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
    sort(s[i].begin(), s[i].end());
  }
  sort(s, s+n);
  // for(int i = 0; i < n; i++) cout << s[i] << endl;
  long long now = 0;
  long long ans = 0;
  for(long long i = 1; i < n; i++){
    if(s[i] != s[i-1]){
      ans += (i-now) * (i-now-1) / 2;
      now = i;
      // cout << now << endl;
    }
    if(i == n - 1){
      ans += (i+1 - now) * (i+1 - now-1) / 2;
    }
  }
  cout << ans << endl;


  return 0;
}