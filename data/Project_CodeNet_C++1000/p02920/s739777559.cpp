#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using int64 = long long;

int main()
{
  int n;
  cin >> n;
  int count = 1 << n;
  vector<int64> s(count);
  
  for (int i = 0; i < count; ++i)
  {
    cin >> s[i];
  }
  sort(s.begin(), s.end(), greater<int64>());
  
  vector<int64> parent;
  parent.push_back(s[0]);
  for (int t = 0; t < n; ++t)
  {
    vector<int64> currentParent(parent);
    int pi = 0;
    int psize = currentParent.size();
    for (int i = 1; (i < count) && (pi < psize); ++i)
    {
      if (s[i] == -1) continue;
      if (s[i] < currentParent[pi])
      {
        parent.push_back(s[i]);
        s[i] = -1;
        ++pi;
      }
    }
    if (pi < psize)
    {
      cout << "No" << endl;
      return 0;
    }
    sort(parent.begin(), parent.end(), greater<int64>());
  }
  cout << "Yes" << endl;
  return 0;
}
