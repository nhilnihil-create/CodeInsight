#include<iostream>
#include<algorithm>
using namespace std;
int main ()
{
   int a,b,c,d;
   cin>>a>>b>>c>>d;
   bool t=true;
   while(t=true)
   {
     c=c-b;
    if(c<=0)
    {
    cout<<"Yes";
    break;
    }
     a= a-d;
    if(a<=0)
    {
    cout<<"No";
    break;
    }

    }
}