#include<iostream>
using namespace std;
int main()
{
    long long n,p;
    cin>>n;
    p=n/2;
    if(n%2!=0)
    {
        p++;
    }
    cout<<p<<endl;
    return 0;
}