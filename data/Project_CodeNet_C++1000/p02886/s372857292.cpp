#include <iostream>
using namespace std;

int main()
{
  int n, i=0;
  unsigned long long ans = 0;
  int d[50];
  
  cin >> n;
  
  for(int i=0; i<n; i++)
  {
    cin >> d[i];
  }
  
  for(int i=0; i<n-1; i++)
  {
    for(int j=i+1; j<n; j++)
    {
      ans += d[i] * d[j];
    }
  }
  cout << ans << endl;
  return 0;
}