#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
  string s;
  cin >> s;
  sort(ALL(s));
  bool ok = true;
  if(s[0] != s[1]) ok = false;
  if(s[2] != s[3]) ok = false;
  if(s[1] == s[2]) ok = false;

  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}