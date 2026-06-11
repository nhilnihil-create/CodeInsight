#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define what_is(x) cerr << #x << " = " << x << endl;
typedef long long ll;
ll pra[1000009];
ll prb[1000009];
int main()
{
    fastIO
    ll n,m,k;

    cin>>n>>m>>k;

    vector<ll>a(n);
    vector<ll>b(m);
    pra[0]=0;
    prb[0]=0;
    for (int i=0; i<n; ++i)
        cin>>a[i],pra[i+1]=pra[i]+a[i];
    for (int i=0; i<m; ++i)
        cin>>b[i],prb[i+1]=prb[i]+b[i];

    ll ans1=0,j=m;
    for ( int i=0; i<=n; ++i)
    {
        if (pra[i]>k)
            break;
        while(pra[i]+prb[j]>k)
            --j;

        ans1=max(ans1,j+i);
    }
    cout<<ans1;


}
