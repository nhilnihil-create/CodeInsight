#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n;
int main()
{
    cin>>n;
    long long p=ceil(sqrt(n*1.0));
    for(long long i=p;i>=1;i--)
    {
        if(n%i==0)
        {
            cout<<(long long)i+(n/i)-2LL<<endl;
            break;
        }
    }
    return 0;
}