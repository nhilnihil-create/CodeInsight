#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int a[100010],w[100010];
int ac,wa;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int p;
        str s;
        cin>>p>>s;

        if(s=="AC")
        {
            if(a[p]==0)ac++;
            a[p]=1;
        }
        else if(s=="WA")
        {
            if(a[p]==0)w[p]++;
        }
    }

    for(int i=1;i<=n;i++)if(a[i]==1)wa+=w[i];

    cout<<ac<<" "<<wa;

    return 0;
}
