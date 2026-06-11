#include<iostream>
using namespace std;

int main()
{
    int a,b,n,f=0,i;
    cin>>n;
    for(i=1;i<=9;i++)
    {
    if(n%i==0&&(n/i)<=9)
    {
    f=1;
    break;
    }
    }
    if(f)cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}