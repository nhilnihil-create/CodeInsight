#include<bits/stdc++.h>
using namespace std;

int main() 
{
    long H;
    cin>>H;

    if(H==1)
    {
        cout<<"1"<<endl;
        return 0;
    }

    long cnt=0;
    while (H>0)
    {
        H/=2;
        ++cnt;
    }

    long ans=1;
    for (long i = 1; i < cnt; ++i)
    {
        long p=1,j=i;
        while (j>0)
        {
            p*=2;
            --j;
        }
        
        ans+=p;
    }
    cout<<ans<<endl;
}