#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  char c = s[0];
  int ans = 1;
  for(int i = 1; i < n; i++){
    if(c != s[i]){
      ans++;
      c = s[i];
    }
  }
  cout << ans << endl;

  return 0;
}