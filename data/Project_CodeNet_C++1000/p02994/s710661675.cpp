#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n, l;
  long long score = 0;
  cin >> n >> l;
  vector<int> dif(n);
  for(int i=0; i<n; i++)
  {
    dif[i] = abs(l + i);
    score += l + i;
  }
  
  vector<int>::iterator erase_it = min_element(dif.begin(), dif.end());
  int erase_idx = distance(dif.begin(), erase_it);
  score -= l + erase_idx;
  cout << score << endl;
  return 0;
}