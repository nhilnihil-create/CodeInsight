#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, k, ans = 0;
  cin >> n >> k;
  vector<bool> flag;
  for(int i=0; i<n; i++)
    flag.push_back(true);
  
  for(int i=0; i<k; i++)
  {
    int d;
    cin >> d;
    for(int j=0; j<d; j++)
    {
      int a;
      cin >> a;
      flag[--a] = false;
    }
  }
  
  for(int i=0; i<n; i++)
  {
    if(flag[i])
      ans++;
  }
  
  cout << ans << endl;
  return 0;
}