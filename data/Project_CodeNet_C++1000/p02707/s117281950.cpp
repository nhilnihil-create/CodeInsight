#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; cin >> n;
  vector<vector<int> > a(n);
  for (size_t i = 1; i < n; i++)
  {
    int tmp; cin >> tmp;
    tmp--;
    a[tmp].push_back(i);
  }
  for (auto &&i : a)
  {
    cout << i.size() << endl;
  }
  
  
}