#include <bits/stdc++.h>
using namespace std;

int aa[100010],bb[100010];

#define INF 1000000

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a,b,m;
    cin>>a>>b>>m;

    int mina=INF,minb=INF;

    for(int i=0;i<a;i++)
    {
        cin>>aa[i];
        mina=min(mina,aa[i]);
    }
    for(int i=0;i<b;i++)
    {
        cin>>bb[i];
        minb=min(minb,bb[i]);
    }

    int ans=mina+minb;

    for(int i=0;i<m;i++)
    {
        int x,y,c;
        cin>>x>>y>>c;

        ans=min(ans,aa[x-1]+bb[y-1]-c);
    }

    cout<<ans<<"\n";

    return 0;
}
