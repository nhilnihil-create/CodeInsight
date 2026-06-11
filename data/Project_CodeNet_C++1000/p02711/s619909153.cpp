#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using P = pair<int, int>;
int main()
{
  string s;
  cin >> s;
  bool ans = false;
  rep(i,3){
    if(s.at(i) == '7') ans = true;
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

return 0;
}