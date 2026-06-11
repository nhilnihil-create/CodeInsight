#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  string s;
  cin >> s;
  int ans = 7;
  if(s == "MON") ans -= 1;
  else if(s == "TUE") ans -= 2;
  else if(s == "WED") ans -= 3;
  else if(s == "THU") ans -= 4;
  else if(s == "FRI") ans -= 5;
  else if(s == "SAT") ans -= 6;
  cout << ans << endl;
  return 0;
}