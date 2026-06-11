#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  string s;
  cin >> s;
  bool ok=true;
  for(int i = 0; i < s.size()-1; i++) {
    if(s[i]==s[i+1]) ok=false;
  }
  cout << (ok? "Good":"Bad") << endl;
  return 0;
}