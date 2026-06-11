#include<iostream>
using namespace std;
int main()
{
    long long n,a,b,l,k,m,s,h,total;
    cin>>n>>a>>b;
    l=a+b;
    k=n/l;
    m=n%l;
    if(m<=a)
    {
        h=m;
    }
    else
    {
        h=a;
    }
    total=(k*a)+h;
    cout<<total<<endl;
    return 0;
}