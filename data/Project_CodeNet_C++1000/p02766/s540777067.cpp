#include <iostream>
using namespace std;

int main()
{
  int n, k, res = 1;
  cin >> n >> k;
  while(n /= k)
    res++;
  
  cout << res << endl;
  return 0;
}