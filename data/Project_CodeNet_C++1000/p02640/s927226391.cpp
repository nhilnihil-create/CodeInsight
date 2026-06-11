#include <iostream>

using namespace std;

int main()
{
int X , Y ;
int sum;
cin >> X >> Y;
for(int i = 0; i <= X;i++)
{
  sum = 2*i + 4*(X-i);
    if(sum == Y)
    {
      cout << "Yes" << endl;
      break;
    }
}
  if(sum != Y)
  {
     cout << "No" << endl;
  }
  return 0;
}
