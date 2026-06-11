#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n; cin >> n;
  string s; cin >> s;
  
  int ans = 1;
  for(int i = 0; i < n-1; i++){
    if(s[i] != s[i+1]){
      ans++;
    }
  }
  
  cout << ans << endl;
}
