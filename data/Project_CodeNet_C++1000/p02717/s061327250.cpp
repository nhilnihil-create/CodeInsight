#include<iostream>
using namespace std;

int main()
{
   int a,b,c,x,y,z;
   cin>>x>>y>>z;
   a=x;
   b=y;
   c=z;
   swap(a,b);
   swap(a,c);
   cout<<a<<" "<<b<<" "<<c<<endl;
    return 0;
}
