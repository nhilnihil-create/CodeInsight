#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t,a,k;
    cin>>t>>a>>k;
    
    if(k<=t)
    {
        t=t-k;
        k=0;
    }
    else
    {
        k=k-t;
        t=0;
    }
    if(k<=a)
    {
        a=a-k;
        k=0;
    }
    else
    {
        
        k=k-a;
        a=0;
    }
    
    cout<<t<<" "<<a;
    
    return 0;
}