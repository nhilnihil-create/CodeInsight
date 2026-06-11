#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, ans = 0;
  cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; i++)
    cin >> v[i];
  
  for(int i=1; i<n-1; i++)
  {
    if(v[i-1] < v[i] && v[i] < v[i+1])
      ans++;
    else if(v[i+1] < v[i] && v[i] < v[i-1])
      ans++;
  }
  
  cout << ans << endl;
  return 0;
}