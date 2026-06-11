


#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,k;
    cin>>a>>b>>k;
    if((a+b)<=k)
    {
        cout<<0<<' '<<0;
        return 0;
    }
    if(a>=k)
    {
        cout<<(a-k)<<' '<<b;
    }
    else
    {
        cout<<0<<' '<<a+b-k;
    }
    return 0;
}

