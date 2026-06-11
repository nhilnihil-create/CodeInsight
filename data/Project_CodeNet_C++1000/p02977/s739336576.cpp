#include <bits/stdc++.h>
using namespace std;

void writeEdge(int x, int y)
{
  cout << x << ' ' << y << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  if (n == 1) cout << "No\n";
  else
  {
    int x = 0;
    if (n % 2) x = -1;
    else
      for (int i = 1; i < n; i++)
        if ((n ^ i) < n)
          x = i;

    if (!x) cout << "No\n";
    else
    {
      cout << "Yes\n";
      for (int i = 2; i < n; i += 2)
      {
        writeEdge(i, i + 1);
        writeEdge(i + 1, 1);
        writeEdge(1, i + n);
        writeEdge(i + n, i + n + 1);
      }
      writeEdge(n + 1, 2);
      if (x > 0)
      {
        if (x % 2) writeEdge(n, x);
        else writeEdge(n, x + n);
        int y = n ^ x ^ 1;
        if (y % 2) writeEdge(n + n, y);
        else writeEdge(n + n, y + n);
      }
    }
  }
}
