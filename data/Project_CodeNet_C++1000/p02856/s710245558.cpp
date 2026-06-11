#include <iostream>

using namespace std;
long long n,i,s,d,val, nr;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>val>>nr;
        s+=nr*val;
        d+=nr;
    }
    s-=9;
    if(s<=0)
    {
        s=0;
    }
    else
    {
        if(s%9==0)
            s=s/9;
        else
            s=s/9+1;
    }

    cout<<d-1+ s;
    return 0;
}
