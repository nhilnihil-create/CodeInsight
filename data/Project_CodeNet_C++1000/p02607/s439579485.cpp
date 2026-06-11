#include<iostream>
using namespace std;

int main()
{
  int n,c=0;
  cin >> n;
  int ar[n];
  for(int i=1;i<=n;i++)
  {
    cin >> ar[i];
  }
  
  for(int i=1;i<=n;i++)\
  {
    if((i%2!=0) && (ar[i]%2!=0))
      c++;
  }
  
  cout << c;
  return 0;
}