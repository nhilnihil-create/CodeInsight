#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define mp make_pair
#define PI acos(-1)
using namespace std;
ll a[1000005],cnt[1000005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i,j,k,x,y,z,m,n,t,l,r;
    cin>>n;
    ll g=0;
    for(i=1; i<=n; i++)
    {
        cin>>a[i];
        g=__gcd(g,a[i]);
        cnt[a[i]]++;
    }
    if(g>1)
    {
        cout<<"not coprime"<<'\n';
        return 0;
    }
    bool monu=1;
    ll val;
    for(i=2; i<1000000; i++)
    {
        val=0;
        for(j=i; j<1000000; j+=i)
        {
            val+=cnt[j];
        }
        if(val>1)
            monu=0;
    }
    if(monu)
        cout<<"pairwise coprime"<<'\n';
    else
        cout <<"setwise coprime"<<'\n';
}




