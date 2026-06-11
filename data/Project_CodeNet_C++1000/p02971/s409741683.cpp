#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i, n) for (int i = 0; i < (n); i ++)
using namespace std;

int main()
{
  int n;
  cin >> n;
  
  vector<int> a_times(200001);
  vector<int> a(n);
  int tmp;
  rep(i, n)
  {
    cin >> tmp;
    a.at(i) = tmp;
    a_times.at(--tmp) ++;
  }
  
  int max = *max_element(a.begin(), a.end());
  
  rep(i, n)
  {
    if (a.at(i) < max)
    {
      cout << max << endl;
      continue;
    }
    else if (a_times.at(max - 1) > 1)
    {
      cout << max << endl;
      continue;
    }
    
    for (int j = max - 2; j >= 0; -- j)
    {
      if (a_times.at(j) > 0)
      {
        cout << j + 1 << endl;
        break;
      }
    }
  }
  
  return 0;
}