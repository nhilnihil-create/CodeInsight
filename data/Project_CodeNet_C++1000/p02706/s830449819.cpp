#include <iostream>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  long long ans = n;
  
  for(int i=0; i<m; i++)
  {
    int a;
    cin >> a;
    ans -= a;
  }
  
  cout << (ans >= 0 ? ans : -1) << endl;
  return 0;
}