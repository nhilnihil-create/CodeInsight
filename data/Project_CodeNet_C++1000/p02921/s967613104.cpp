#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){

  string s, t;
  cin >> s;
  cin >> t;
  int cnt = 0;
  if(s[0] == t[0]) ++cnt;

  if(s[1] == t[1]) ++cnt;

  if(s[2] == t[2]) ++cnt;

  cout << cnt << endl;

  return 0;
}