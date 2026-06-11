#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int xm=1000000,ym=10000000,a,b,m;
    long int ans=1000000;
    cin>>a>>b>>m;
    long int x[a],y[b];
    for(int i=0;i<a;i++)
        {
            scanf("%ld",&x[i]);
            xm=min(xm,x[i]);
        }
    for(int i=0;i<b;i++)
        {
            scanf("%ld",&y[i]);
            ym=min(ym,y[i]);
        }
    for(int i=0;i<m;i++)
    {
        int p,q,c;
        cin>>p>>q>>c;
        ans=min(ans,x[p-1]+y[q-1]-c);
    }
    cout<<min(ans,xm+ym);
    return 0;
}

