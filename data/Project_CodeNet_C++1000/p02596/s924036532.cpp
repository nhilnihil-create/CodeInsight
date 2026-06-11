#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int maxn=2e5+10;
const int mod=1e9+7;

ll k;

ll power(ll base,ll n)
{
    ll r=1;
    while(n)
    {
        if(n%2) r=r*base%k;
        base=base*base%k;
        n/=2;
    }
    return r;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>k;
    ll sum=0;
    int len=1;
    while(1)
    {
        sum+=power(10,len-1)*7;
        sum%=k;
        if(sum%k==0)
        {
            cout<<len<<'\n';
            return 0;
        }
        len++;
        if(len>1e6)
        {
            cout<<-1<<'\n';
            return 0;
        }
    }



}