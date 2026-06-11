#include<iostream>
using namespace std;
int main()
{
    long long n,k,l,m;
    cin>>n>>k;
    l=n%k;
    if(l<=k)
    {
        m=k-l;
    }
    else
    {
        m=l-k;
    } 
    if(m<0)
    {
        cout<<l<<endl;
    }
    else
    {
        if(m<=l)
        {
            cout<<m<<endl;
        }
        else
        {
            cout<<l<<endl;
        }
    }
    return 0;
}