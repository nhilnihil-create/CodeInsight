#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  string s;
  cin >> s;
  // 排他的論理和
  s[1] = 'R'^'B'^s[1];
  cout << s << endl;
  return 0;
}