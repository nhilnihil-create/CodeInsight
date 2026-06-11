#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);
typedef pair<int,int> P;
const int INF = 1001001001;


int main() {
  string s;
  cin >> s;
  if(s[s.size()-1] == 's') cout << s << "es" << endl;
  else cout << s << "s" << endl;
  return 0;
}