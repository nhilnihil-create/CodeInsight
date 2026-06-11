#include <iostream>
using namespace std;

int fizzbuzz(int a)
{
  if(a % 3 == 0 && a % 5 == 0)
    return 0;
  else if(a % 3 == 0)
    return 0;
  else if(a % 5 == 0)
    return 0;
  else
    return a;
}

int main()
{
  int n;
  long long ans = 0;
  cin >> n;
  for(int i = 1; i <= n; i++)
    ans += fizzbuzz(i);
  
  cout << ans << endl;
  return 0;
}