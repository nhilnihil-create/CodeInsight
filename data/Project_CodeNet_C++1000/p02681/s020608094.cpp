#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  string s, t;
  cin >> s >> t;

  bool a = true;
  rep(i, s.size()){
    if (s.at(i) != t.at(i)) a = false;
  }

  if (a) cout << "Yes" << endl;
  else cout << "No" << endl;
}
