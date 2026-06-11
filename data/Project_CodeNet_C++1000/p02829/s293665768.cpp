#include <iostream>
using namespace std;

int main()
{
  int num1,num2,num3;
  num3 = 0;
  cin >> num1 >> num2;

  if(num1 == 1 && num2 == 2)
  {
    num3 = 3;
  }
  else if(num1 == 1 && num2 == 3)
  {
    num3 = 2;
  }
  else if(num1 == 2 && num2 == 3)
  {
    num3 = 1;
  }
  else if(num1 == 2 && num2 == 1)
  {
    num3 = 3;
  }
  else if(num1 == 3 && num2 ==2)
  {
    num3 = 1;
  }
  else
  {
    num3 = 2;
  }
  cout << num3 << endl;
}
