#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s, t;
  cin >> s >> t;
  int ans = 100000;
  string temp;
  for (int i=0; i<(s.size()-t.size()+1); i++){
    int cnt = 0;
    for (int j=i, k=0; k<t.size() ; j++, k++){
      if (s[j] != t[k]){
        cnt += 1;
      }
    }
    if (cnt < ans) ans = cnt;
  }
  cout << ans << endl;
}