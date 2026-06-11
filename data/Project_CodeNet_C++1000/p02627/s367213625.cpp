#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P  = pair <int, int>;

#define rep(i, n)     for (int i = 0; i < (int) (n); i++)
#define repr(i, a, b) for (int i = a; i < b; i++)
#define each(i, mp)   for (auto &i : mp)

const int INF = 1001001001;

int main()
{
  string s;
  cin >> s;
  char   ans    = 'A';
  string komoji = "qwertyuiopasdfghjklzxcvbnm";
  rep(i, komoji.size()) {
    if (s[0] == komoji[i]) {
      ans = 'a';
    }
  }
  cout << ans << endl;

  return 0;
}
