#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define forn(i,n) for(int i=0; i<(int)n; i++)
ll power(ll x,ll n);
bool isprime(ll n);
ll mod=1e9+7;


void test_case()
{
    ll a,b;
    cin>>a>>b;
    cout<<a*b;
}

int main()
{
    fastio
//    int t;
//    cin>>t;
//    while(t--)
    test_case();
}
ll power(ll x,ll n)
{
    ll ans=1;
    while(n>0) {
        if(n&1)
            ans*=x;
        n>>=1;
        x*=x;
    }
    return ans;
}

bool isprime(ll n)
{
    if(n==2 || n==3)
        return true;
    if(n<=1 || n%2==0 || (n%6!=1 && n%6!=5))
        return false;
    for(int i=3;i*i<=n;i+=2) {
        if(n%i==0)
            return false;
    }
    return true;
}
