#include <iostream>
using namespace std;

bool is_prime(int x)
{
  if(x==1) return true;
  for(int i = 2; i*i <= x; ++i)
  {
    if(x%i == 0) return false;
  }
  return true;
}

int main()
{
  int x;
  cin >> x;
  while(!is_prime(x))
  {
    ++x;
  }
  cout << x << endl;
}