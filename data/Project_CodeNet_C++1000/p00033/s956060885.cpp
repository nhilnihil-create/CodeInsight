#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

#define pb push_back

bool dfs(vi& a, int i, int b, int c)
{
  if (i == 10)
    return true;
  if (b < a[i] && dfs(a, i+1, a[i], c))
    return true;
  if (c < a[i] && dfs(a, i+1, b, a[i]))
    return true;
  return false;
}

int main(int argc, char **argv)
{
  int n, x;
  cin >> n;
  while (n--) {
    vi a;
    for (int i = 0; i < 10; i++) {
      cin >> x;
      a.pb(x);
    }
    if (dfs(a, 0, 0, 0))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}