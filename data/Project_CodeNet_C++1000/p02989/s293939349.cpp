#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> d(n);
  for(int i = 0; i < n; ++i) cin >> d[i];
  
  sort(d.begin(), d.end());
  int l = d[n/2-1], r = d[n/2];
  
  cout << r - l << endl;
}