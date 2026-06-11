#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    long long a,b,k;
    cin>>a>>b>>k;
    if(a>=k)
    {
        a-=k;
        k=0;
    }
    else
    {
        k-=a;
        a=0;
    }
    if(k!=0)
    {
        if(b>=k) b-=k;
        else b=0;
    }
    cout<<a<<" "<<b;
}