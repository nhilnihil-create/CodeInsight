#include <iostream>
using namespace std;

int main()
{
  int vac, assign, sum;
  sum = 0;

  cin >> vac >> assign;
  int day[assign];


  for(int i=0; i<assign ; i++)
  {
    cin >> day[i];
    sum += day[i];
  }

  if(sum > vac)
  {
    cout << "-1" << endl;
  }
  else if(sum == vac)
  {
    cout << "0" << endl;
  }
  else
  {
    cout << vac - sum << endl;
  }

}
