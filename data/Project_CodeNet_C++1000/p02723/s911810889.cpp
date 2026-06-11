#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 60);

int main() {
  string s;
  cin >> s;
  if (s[2] == s[3] && s[4] == s[5]) cout << "Yes" << endl;
  else cout << "No" << endl; 
  return 0;
} 