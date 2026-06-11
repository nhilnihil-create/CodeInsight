#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,d,p;
  cin>>n>>d;
  p=2*d+1;
  int q=n/p;
  if(n%p!=0)q++;
  cout<<q;
  return 0;
}