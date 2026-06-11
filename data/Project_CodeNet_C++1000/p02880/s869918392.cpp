#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main()
{
  int n;
  cin >> n;
  bool ok = false;
  for (int i = 1; i <= 9; i++)
  {
    for (int j = 1; j <= 9; j++) {
      if(n == i * j) {
        ok = true;
        break;
      }
    }
  }
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}