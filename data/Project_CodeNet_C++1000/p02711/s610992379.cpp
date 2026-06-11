#include <iostream>
using namespace std;

int main()
{
  int num;
  cin >> num;

  //cout << num % 10 << endl;
//  cout << num / 10 << endl;

  if(num%10 == 7)
    {
      cout << "Yes" << endl;
    }

  else
  {
    while(num > 0)
      {
        num /= 10;
        if (num%10 == 7)
          {
            cout << "Yes" << endl;
            break;
          }
      }
      if (num == 0)
        cout << "No" << endl;
  }
}
