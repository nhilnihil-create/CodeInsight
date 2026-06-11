#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  string ans;
  rep(i, n-1) {
    if(s[i] != s[i+1]) ans+=s[i];
  }
  ans+=s[n-1];
  cout << ans.size() << endl;
  return 0;
}