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


int main(){
  int k;
  cin >> k;
  string s;
  cin >> s;
  if (s.size() <= k) cout << s << endl;
  else {
    s.erase(k);
    cout << s << "..." << endl;
  }
  return 0;
}