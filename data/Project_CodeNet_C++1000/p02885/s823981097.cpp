#include <iostream>
using namespace std;
 
int main()
{
 	int a, b;
  cin >> a >> b;
  if(b>=(a+1)/2) cout << 0;   
  else  cout << a-(2*b);
}