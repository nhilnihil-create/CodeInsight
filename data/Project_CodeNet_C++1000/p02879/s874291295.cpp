#include<iostream>
using namespace std;
int main()
{
    int a,b,m;
    cin>>a>>b;
    if((a>=1&&a<=9)&&(b>=1&&b<=9))
    {
        m=a*b;
    cout<<m;
    }
    else
        cout<<"-1";
}
