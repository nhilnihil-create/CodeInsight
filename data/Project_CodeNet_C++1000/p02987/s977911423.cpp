#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  vector<int> A(26, 0);
  for (int i = 0; i < 4; i++)
  {
    A.at((int)(s.at(i) - 'A'))++;
  }
  int cnt = 0;
  for (int i = 0; i < 26; i++)
  {
    if (A.at(i) == 2)
      cnt++;
  }
  cout << (cnt == 2 ? "Yes" : "No") << endl;
}
