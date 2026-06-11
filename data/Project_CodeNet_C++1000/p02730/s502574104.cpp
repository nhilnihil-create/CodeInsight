#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  string s;
  cin >> s;
  int n = s.length();

  string rev1 = s;
  reverse(rev1.begin(), rev1.end());
  if (s != rev1)
  {
    cout << "No" << endl;
    return 0;
  }
  string s2 = s.substr(0, (n - 1) / 2);
  string rev2 = s2;
  reverse(rev2.begin(), rev2.end());
  if (s2 != rev2)
  {
    cout << "No" << endl;
    return 0;
  }
  string s3 = s.substr(((n + 3) / 2) - 1, n);
  string rev3 = s3;
  reverse(rev3.begin(), rev3.end());
  if (s3 != rev3)
  {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}
