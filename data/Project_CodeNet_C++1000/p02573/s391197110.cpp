/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

long long par[200007],mx=1,sz[200007];

void mk(long long n)
{
    long long i;
    for(i=0;i<=n;i++)
    {
        par[i]=i;
        sz[i]=1;
    }
}

long long fin(long long a)
{
    if(par[a]==a)
    {
        return a;
    }
    return par[a]=fin(par[a]);
}

void uni(long long a,long long b)
{
    a=fin(a);
    b=fin(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        mx=max(mx,sz[a]);
    }
     mx=max(mx,sz[a]);mx=max(mx,sz[b]);
}

int main()
{
    long long n,m,i,x,y;
    cin>>n>>m;
  mk(n+1);
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        uni(x,y);
    }
    cout<<mx;
    return 0;
}
