#include <iostream>
using namespace std;

int main()
{
  int room, curtain;

  cin >> room >> curtain;

  if(room / curtain >= 2)
  {
    cout << room - (curtain * 2) << endl;
  }
  else
  {
    cout << 0 << endl;
  }
}
