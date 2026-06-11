#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  int n,k;
  string s;
  cin >> n >> k;
  cin >> s;

  int ans = 0;
  for(int i = 0; i < n-1; i++){
    if(s[i] == s[i+1]) ans ++;
  }
  ans += 2 * k;
  cout << min(ans, n - 1) << endl;

  return 0;
}