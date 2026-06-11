#include<iostream>
using namespace std;
int main()
{
    long long int a,b,k;
    cin>>a>>b>>k;
    if(k>=a)
    {
        cout<<"0"<<" ";
        if(k-a<b)
        {
            cout<<b-(k-a)<<" ";
        }
        else
        {
            cout<<"0"<<" ";
        }
    }
    else
    {
        cout<<a-k<<" ";
        cout<<b<<" ";
    }

          return 0;
}
