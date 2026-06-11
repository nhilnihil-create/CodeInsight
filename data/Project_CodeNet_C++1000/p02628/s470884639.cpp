#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n, k, p, ans = 0;
  vector<int> pn;
  cin >> n >> k;
  while(cin >> p)
  {
    pn.push_back(p);
  }
  sort(pn.begin(), pn.end());
  for(int i=0; i<k; i++)
    ans += pn[i];
  
  cout << ans << endl;
  return 0;
}