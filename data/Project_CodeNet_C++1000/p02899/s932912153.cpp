#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  for(int i = 0; i < n; ++i)
  {
    int num;
    cin >> num;
    a.push_back({num, i+1});
  }
  
  sort(a.begin(), a.end());

  for(int i = 0; i < n; ++i)
  {
    cout << a[i].second << " ";
  }
}