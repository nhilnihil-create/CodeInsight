#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
  string s;
  cin >> s;
  bool ans = false;
  rep(i,3){
    if(s[i] == s[i+1]) ans=true;
  }
  if(ans) cout << "Bad" << endl;
  else cout << "Good" << endl;
}
