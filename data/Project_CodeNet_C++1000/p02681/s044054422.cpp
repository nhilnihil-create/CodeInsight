#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  string s,t;
  cin >> s >> t;
  string ans = "Yes";
  rep(i,s.size()){
    if(s.at(i) != t.at(i))ans = "No";
  }
  cout << ans << endl;
}