#include<iostream>
using namespace std;
int main()
{
    long long n,m,s=0,k;
    cin>>n;
    if(n%2!=0)
    {
        cout<<0<<endl;
    }
    else
    {
        k=10;
        while(k<=n)
        {
            s+=(n/k);
            k*=5;
        }
        cout<<s<<endl;
    }
    return 0;
}
