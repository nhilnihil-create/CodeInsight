#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m,v,p,a[200001];
bool ok(int poz)
{
    ll nr=a[poz]+m;
    ll nrop=m*(v-1);
    ll nrmari=0;
    for(int i=1;i<=n;i++)
        if(a[i]>nr&&i!=poz)
        {
            nrop-=m;
            nrmari++;
        }
    for(int i=1;i<=n;i++)
        if(a[i]<=nr&&i!=poz)
        {
            ll dif=nr-a[i];
            nrop-=min(dif,m);
        }
    for(int i=n;i>=1&&nrmari<p-1;i--)
    {
        if(i!=poz)
        {
            ll dif=nr-a[i];
            if(dif<=m&&dif>=0)
            {
                nrop-=(m-dif);
                nrmari++;
            }
        }
    }
    if(nrmari<=p-1&&nrop<=0)
        return 1;
    return 0;
}
int main()
{
    cin>>n>>m>>v>>p;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int st=1;
    int dr=n;
    int pozmin=n+1;
    //cout<<ok(3)<<'\n';
    while(st<=dr)
    {
        int mij=(st+dr)/2;
        if(ok(mij))
        {
            if(mij<pozmin)
                pozmin=mij;
            dr=mij-1;
        }
        else
            st=mij+1;
    }
    cout<<n-pozmin+1;
    return 0;
}
