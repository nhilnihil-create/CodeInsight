#include <iostream>

using namespace std;

int main()
{
int a,b;
cin>>a;
cin>>b;
int s=0;
if(1<=a&&a<=10000&&1<=b&&b<=10000)
{
while(a>0)
{
    a=a-b;
    s++;
}
cout<<s;
}

else
{
    cout<<"error";
}
    return 0;
}