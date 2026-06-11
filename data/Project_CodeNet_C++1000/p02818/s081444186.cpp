#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,k;
    cin>>a>>b>>k;
    if(k<a)
    {
        cout<<a-k<<" "<<b;
    }
    else
    {
        k=k-a;
        if(k<b)
        {
            b= b-k;
        }
        else b=0;
        cout<<0<<" "<<b;
    }
    return 0;
}
