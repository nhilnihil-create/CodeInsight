//わからなかった

#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  string s;
  cin >> s;

  sort(all(s));
  if (s[0] == s[1] && s[1] != s[2] && s[2] == s[3]) cout << "Yes" << endl;
  else cout << "No" << endl;
}
