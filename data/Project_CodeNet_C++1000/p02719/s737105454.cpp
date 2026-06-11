#include<iostream>
using namespace std;
int main()
{
    long long n,k,l,m;
    cin>>n>>k;
    l=n%k;
    m=k-l; 
    if(m<=l)
    {
        cout<<m<<endl;
    }
    else
    {
        cout<<l<<endl;
    }
    return 0;
}