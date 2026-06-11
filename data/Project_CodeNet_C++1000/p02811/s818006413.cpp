#include <iostream>
using namespace std;

int main()
{
  int k, x;
  cin >> k >> x;
  
  int res = k * 500;
  if (res >= x) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}