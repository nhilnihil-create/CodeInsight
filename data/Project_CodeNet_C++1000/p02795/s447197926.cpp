#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,cnt=0,b,c,d;
    cin>>n>>m>>a;
    if(n>m)
    {
        c=a/n;
        d=a%n;
        if(d>0)
        {
            cnt=1;
        }
        cout<<(c+cnt)<<endl;
    }
    else
    {
        c=a/m;
        d=a%m;
        if(d>0)
        {
            cnt=1;
        }
        cout<<(c+cnt)<<endl;
    }
    return 0;
}
