#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  string s, t;
  cin >> s >> t;
  t.pop_back();
  cout << (s == t? "Yes" : "No") << endl;
  return 0;
}