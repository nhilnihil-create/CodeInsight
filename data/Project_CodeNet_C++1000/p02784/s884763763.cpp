#include<iostream>
using namespace std;
int main()
{
    long long h,a,t=0,n;
    cin>>h>>n;
    while(n--)
    {
        cin>>a;
        t+=a;
    }
    if(h<=t)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}