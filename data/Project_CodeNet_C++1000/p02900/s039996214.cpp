#include<bits/stdc++.h>
typedef long long ll;
const ll mod=1e9+7;
using namespace std;
vector<int> v;
int isp[1000006];
int bm1[1000005];
int bm2[1000005];
void ola(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(isp[i]==0) v.push_back(i);
        for(int j=0;v[j]<n/i;j++)
        {
            isp[v[j]*i]=1;
            if(i%v[j]==0) break;
        }
    }
}
int main()
{
    ola(1000000);
    ll a,b;
    cin>>a>>b;
    for(int i=0;i<v.size();i++)
    {
        while(a%v[i]==0)
        {
            a/=v[i];
            bm1[v[i]]=1;
        }
    }
    for(int i=0;i<v.size();i++)
    {
        while(b%v[i]==0)
        {
            b/=v[i];
            bm2[v[i]]=1;
        }
    }
    int ans=0;
    for(int i=0;i<=1000001;i++)
    {
        if(bm1[i]==1&&bm1[i]==bm2[i])
            ans++;
    }
    if(a==b&&a!=1) ans++;
    cout<<ans+1<<endl;
    return 0;
}
