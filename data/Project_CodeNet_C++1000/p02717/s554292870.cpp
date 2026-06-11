#include <iostream>
using namespace std;

int main()
{
  int n[3];
  int temp, i = 0;
  while(cin >> temp)
  {
    n[i] = temp;
    i++;
  }
  cout << n[2]<< " " << n[0] << " " << n[1] << endl;
  return 0;
}