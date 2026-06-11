#include <iostream>
using namespace std;

int main()
{
  int temp, sum;
  while(cin >> temp) sum += temp;
  
  if(sum > 21) cout << "bust";
  else cout << "win";
  cout << endl;
  return 0;
}