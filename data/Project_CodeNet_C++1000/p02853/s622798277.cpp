#include<bits/stdc++.h>
using namespace std;
#define NL            "\n"
#define _SAD()        ios::sync_with_stdio(0),cin.tie(0), cout.tie(0);
#define SZ(s)         s.size()
#define SRT(x,y)      sort(x,x+y)
#define REV(a,b)      reverse(a,a+b)
#define VSRT(x)       sort(x.begin(),x.end())
#define VREV(x)       reverse(x.begin(),x.end())
int a[206],b[206];
int main()
{
    _SAD()
    int x,y;
    cin>>x>>y;
    a[1]=300000;
    b[1]=300000;
    a[2]=200000;
    b[2]=200000;
    a[3]=100000;
    b[3]=100000;
    if(x==1&&y==1)
    {
        cout<<"1000000"<<NL;
    }
    else
    {
        cout<<a[x]+b[y]<<NL;
    }
    return 0;
}
