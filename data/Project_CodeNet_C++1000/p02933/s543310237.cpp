#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main()
{
  int a;
  cin >> a;
  string s;
  cin >> s;
  if(a >= 3200) cout << s << endl;
  else cout << "red" << endl;
  return 0;
}