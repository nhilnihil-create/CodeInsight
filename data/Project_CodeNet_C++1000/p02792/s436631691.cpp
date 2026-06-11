#include<bits/stdc++.h>
#define ll long long 
#define vl vector
#define pb push_back
#define ff first
#define ss second
using namespace std;

ll fact(ll n)
{
    ll ans=1,i;
    for(i=1;i<=n;i++) ans+=i;
    return ans;
}

ll cnt[10][10];

int main()
{
    ll n,m,i,a,b;
    cin>>n;
    ll ans=0;
    for(i=1;i<=n;i++)
    {
        string s=to_string(i);
        ll front=s[0]-'0',end=s[s.size()-1]-'0';
        ans+=2*cnt[end][front];
        ans+=front==end;
        cnt[front][end]++;
    }
    cout<<ans;
}