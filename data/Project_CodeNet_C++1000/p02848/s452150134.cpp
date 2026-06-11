#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  string s;
  cin >> n >> s;

  for (int i = 0; i < s.size(); i++)
  {
    char c = s[i] + n;
    if (c - '0' > 42)
    {
      c -= 26;
    }

    cout << c;
  }
  cout << endl;
}
