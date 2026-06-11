#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int t=n;
  int total=0;
  while(n>0)
  {
    total+=((t/n)-(t%n==0));
    n--;
  }
  cout<<total<<endl;
  return 0;
}