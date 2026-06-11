#include<iostream>
using namespace std;
int main()
{
  int a,b,c,x,y,z;
  cin>>a>>b>>c;
  x=a;
  a=b;
  b=x;
  y=a;
  a=c;
  c=y;
  cout<<a<<" "<<b<<" "<<c<<endl;




 return 0;
}
