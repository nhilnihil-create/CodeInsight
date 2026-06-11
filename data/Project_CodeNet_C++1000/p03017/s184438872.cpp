#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int n,a,b,c,d;
  string s;
  cin >>n>>a>>b>>c>>d>>s;
  bool sunuke = true, funuke = true;
  a--;b--;c--;d--;
  for (int i = a; i < c; i++) if (s[i] == '#' && s[i+1] == '#') sunuke = false;
  for (int i = b; i < d; i++) if (s[i] == '#' && s[i+1] == '#') funuke = false;
  
  bool can = sunuke && funuke;
  if (!can) {
    cout << "No" << endl;
    return 0;
  }
  
  if (c < d) {
    cout << "Yes" << endl;
  }
  else {
    can = false;
    for (int i = b; i <= d; i++)
    {
      if ((s[i]==s[i-1]&&s[i]==s[i+1]&&s[i]=='.')) {
        can = true;
      }
    }
    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}