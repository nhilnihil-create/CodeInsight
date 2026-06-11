#include <iostream>
using namespace std;

int main()
{
  int n;
  string res = "No";
  cin >> n;
  for(int i=1; i<10; i++)
  {
    if(n % i == 0)
    {
      n /= i;
      if(n <= 9)
      {
        res = "Yes";
        break;
      }
      n *= i;
    }
  }
  cout << res << endl;
  return 0;
}