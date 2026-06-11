#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, last = -1, ans = 0;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for(int i=0; i<n; i++)
    cin >> a[i];
  for(int i=0; i<n; i++)
    cin >> b[i];
  c[0] = 0;
  for(int i=1; i<n; i++)
    cin >> c[i];
  
  for(int i=0; i<n; i++)
  {
    int ai = a[i] - 1;
    if(ai - 1 == last)
      ans += b[ai] + c[ai];
    else
      ans += b[ai];
    
    last = ai;
  }
  
  cout << ans << endl;
  return 0;
}