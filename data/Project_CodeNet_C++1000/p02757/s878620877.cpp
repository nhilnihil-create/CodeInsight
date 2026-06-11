#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int num[200005];
ll C(ll n,ll m)//n<m
{
    ll c[5];
    c[0]=1;
    for(int i=1;i<=n;i++)
    {
        c[i]=((c[i-1]*(m-i+1)))/i;
    }
    return c[n];
}
int main()
{
    int n,p;
    ll ans=0,m=0,maxn=0;
    memset(num,0,sizeof num);
    cin>>n>>p;
    cin>>s;
    if(p==2)
    {
        for(int i=0;i<n;i++)
        {
            if(!((s[i]-'0')&1))ans+=i+1;
        }
        cout<<ans<<endl;
    }
    else if(p==5)
    {
        for(int i=0;i<n;i++)
        {
            if(s[i]=='5'||s[i]=='0')ans+=i+1;
        }
        cout<<ans<<endl;
    }
    else
    {
        int ten=1;
        for(int i=n-1;i>=0;i--)
        {
            m=(m+(s[i]-'0')*ten)%p;
            ten=(ten*10)%p;
            //cout<<m<<endl;
            num[m]++;
            maxn=max(maxn,m);
        }
        //cout<<endl;
        for(int i=0;i<=maxn;i++){ans+=C(2,num[i]);}
        cout<<ans+num[0]<<endl;
        //cout<<ans<<endl;
    }
    return 0;
}
