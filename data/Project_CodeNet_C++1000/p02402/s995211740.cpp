#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
  int n;
  cin >> n;
  int mn = 10000000;
  int mx = -10000000;
  long long sum = 0;
  for(int i=0; i<n; i++){
    int j;
    cin >> j;
    mn = min(mn,j);
    mx = max(mx,j);
    sum += j;
  }
  cout << mn << " " << mx << " " << sum << endl;
  return 0;
}