#include <iostream>
using namespace std;

int main()
{
  int hold, con1, con2, remain;
  remain = 0;

  cin >> hold >> con1 >> con2 ;
  remain = con2 - (hold - con1);

  if((hold-con1) > con2)
  {
    cout << 0 << endl;
  }

  else
  cout << remain << endl;
}
