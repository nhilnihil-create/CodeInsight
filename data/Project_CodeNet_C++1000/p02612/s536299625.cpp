#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  long long n;
  cin >>n;
  long long n1,n2;
  n1=n%1000;
  n2=1000-n1;
  if(n1==0)
  {
      cout << 0 << "\n";
  }
  else
  cout << n2 << "\n";
}