#include <iostream>
using namespace std;
 
int main()
{
  long a, result = 1, sum = 0, l = 1, b[100002];
  cin >> a;
  
  if (a == 0)
  {
    cin >> a;
    cout << (a == 1 ? 1 : -1);
    return 0;
  }
  else
  {
    for (long i=0; i<=a; i++)
    {
      cin >> b[i];
      sum += b[i];
    }
    
    if (b[0] != 0)
    {
      cout << -1;
      return 0;
    }
    
    for (int i=1; i<=a; i++)
    {
      if (l*2 < b[i])
      {
        cout << -1;
        return 0;
      }
      
      if (l*2 < sum)
        l *= 2;
      else
        l = sum;
      
      result += l;
      sum -= b[i];
      l -= b[i];
    }
 
    cout << result;
    return 0;
  }
}