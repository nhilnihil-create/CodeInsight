#include <iostream>
#include <vector>
using namespace std;

int main()
{
  long long n, k, i = 0,ans = 0;
  cin >> n >> k;
  vector<int> h(n);
  while(cin >> h[i])
    i++;
  
  for(int i=0; i<n; i++)
  {
    if(h[i]>=k)
      ans++;
  }
  cout << ans << endl;
}