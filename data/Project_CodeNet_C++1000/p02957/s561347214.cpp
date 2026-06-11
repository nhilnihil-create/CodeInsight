#include<iostream>
using namespace std;
int main()
{
  long long int a, b;
  cin >> a >> b;
  if((a%2==0 && b%2==0) || (a%2!=0 && b%2!=0))
    cout << (a+b)/2 <<"\n";
  else
    cout << "IMPOSSIBLE\n";
  
  return 0;
}