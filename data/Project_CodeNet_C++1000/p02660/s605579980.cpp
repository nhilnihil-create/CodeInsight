#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mx=10000007;
bool mark[mx];
vector<ll>v,freq;
void seive()
{
    ll i,j;
    for(i=2;i+i<=mx;i++)
    {
        if(mark[i]==0){
            v.push_back(i);
            for(j=i;j<=mx;j+=i)mark[j]=1;
        }
    }
}
ll solv(ll x)
{
    for(ll i = 1; i <= 64; i++)
    {
        if((i*(i+1))/2 > x)return i-1;
    }
}
int main()
{
    seive();
    long long int n,ans=0;
    cin>>n;
    long long int m=n;
    for(ll i=0;v[i]*v[i]<=n;i++)
    {
        if(n%v[i]==0)
        {
            ll coun=0;
            while(n%v[i]==0)
            {
                n/=v[i];
                coun++;
            }
            freq.push_back(coun);
        }
    }
    if(n > 1)
        freq.push_back(1);
    for(ll i=0;i<freq.size(); i++)
    {
        ans +=solv(freq[i]);
    }
    cout<<ans<<endl;
}
