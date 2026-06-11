#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;

  int flag = 0;

  vector<int> p(n);

  rep(i, n)
  {
    cin >> p.at(i);
  }

  vector<int> p_tmp(n);

  p_tmp = p;

  sort(p_tmp.begin(), p_tmp.end());

  rep(i, n)
  {
    if (p_tmp.at(i) != p.at(i))
      flag++;
  }

  if (flag == 2 || flag == 0)
    cout << "YES" << endl;
  else
  {
    cout << "NO" << endl;
  }
}
