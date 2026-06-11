#include <bits/stdc++.h>
using namespace std;

#define INF 1e18

using ll = long long;

int p[5010],c[5010];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){cin>>p[i];p[i]--;}
    for(int i=0;i<n;i++)cin>>c[i];

    ll ans=-INF;
    for(int i=0;i<n;i++)
    {
        int pos=i;
        vector<ll> sum;
        sum.push_back(0);
        for(;;)
        {
            pos=p[pos];
            sum.push_back(sum[sum.size()-1]+c[pos]);
            if(pos==i)break;
        }

        int cnt=sum.size()-1;

        ll score=0;
        int ik=min(k,cnt);
        if(sum[cnt]>0)
        {
            score+=((k-1)/cnt)*sum[cnt];
            ik=(k-1)%cnt+1;
        }

        ll smax=-INF;
        for(int j=1;j<=ik;j++)smax=max(smax,sum[j]);
        score+=smax;

        ans=max(ans,score);
    }

    cout<<ans<<"\n";

    return 0;
}
