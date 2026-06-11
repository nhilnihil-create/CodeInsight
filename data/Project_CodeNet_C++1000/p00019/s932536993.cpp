#include<iostream>

using namespace std;

int main()
{
  long long int n;
  cin >> n;
  int i = n;
  while(i-- != 1) n *= i;
  cout << n << endl;;
  
}