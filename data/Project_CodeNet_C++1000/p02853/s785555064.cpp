#include <iostream>
using namespace std;

int main()
{
  int con1, con2, award;
  award = 0;

  cin >> con1 >> con2;

  if(con1 == 3)
  {
    award += 100000;
  }

  else if(con1 == 2)
  {
    award += 200000;
  }

  else if(con1 == 1)
  {
    award += 300000;
  }

  if(con2 == 3)
  {
    award += 100000;
  }
  else if(con2 == 2)
  {
    award += 200000;
  }
  else if(con2 == 1)
  {
    award += 300000;
  }

  if(con1 == 1 && con2 == 1)
  {
    award += 400000;
  }

  cout << award << endl;
}
