#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repc(i, a, b) for (int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;

 
int main() {
  string s, t;
  cin >> s >> t;
  t.erase(t.size()-1);
  if(s == t) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}