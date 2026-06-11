#include <iostream>
using namespace std;

int main()
{
  int k, n;
  cin >> k >> n;
  int idx = n - (k - 1);
  for(int i = 0; i < 2 * k - 1; i++)
  {
    if(i) cout << ' ';
    cout << idx + i;
  }
  cout << endl;
  return 0;
    
}