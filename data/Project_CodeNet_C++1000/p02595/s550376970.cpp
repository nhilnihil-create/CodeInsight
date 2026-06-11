#include <bits/stdc++.h>

using namespace std;

int main()
{
 int n,i,a,b,cont=0;
 double d,x;
 cin>>n;
 cin>>d;
 for(i=0;i<n;i++)
 {
  cin>>a>>b;
  x = sqrt(pow(a,2)+pow(b,2));
  if(x<=d) cont++;	
 }

 cout<<cont;
 return 0;
}