#include<iostream>
using namespace std;
int main()
{
    int a,t;
    cin>>a;
    if(a>=1&&a<=10)
    {
        t=a+(a*a)+(a*a*a);
        cout<<t;
    }
    return 0;
}
