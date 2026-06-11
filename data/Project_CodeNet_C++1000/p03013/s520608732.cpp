#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define pb push_back
#define vl vector
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

ll fib(ll n)
{
    if(n==0) return 0;
    ll a=0,b=1,c,i;
    for(i=2;i<=n;i++)
    {
        c=a+b;
        a=b%MOD;
        b=c%MOD;
    }
    return b%MOD;
}

int main()
{
    ll a,b,i,j,n,t,c,m;
    string s="1";
    cin>>n>>m;
    ll arr[m];
    for(i=0;i<n;i++) s.pb('1');
    for(i=0;i<m;i++) 
    {
        cin>>arr[i];
        s[arr[i]]='0';
    }
    for(i=1;i<m;i++)
    {
        if(arr[i]-arr[i-1]==1)
        {
            cout<<"0";
            return 0;
        }
    }
    ll count=0;
    ll ans=1;
    for(i=0;i<=n;i++)
    {
        if(s[i]=='1') count++;
        else 
        {
            //cout<<fib(count)<<endl;
            ans*=fib(count);
            ans%=MOD;
            count=0;
        }
    }
    ans*=fib(count);
    ans%=MOD;
    cout<<ans;
}