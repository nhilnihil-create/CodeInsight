#include <iostream>
using namespace std;

void judge()
{
  int num;
  cin >> num;

  if(num%10 == 2 || num%10 == 4 || num %10 == 5 || num%10 == 7 || num%10 == 9)
  {
    cout << "hon" << endl;
  }
  //else if(num%10 == 0 || num%10 == 1 || num%10 == 6 || num%10 == 8)
  else if(num%10 == 3)
  {
    cout << "bon" << endl;
  }
  else
  {
    cout << "pon" << endl;
  }
}
int main()
{
  judge();
}
