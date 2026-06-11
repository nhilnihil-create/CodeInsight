#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define vl vector
#define pb push_back
#define ff first
#define ss second
using namespace std;

int main()
{
    ll n,m,i,a=0,b=0,k,t,j;
    cin>>n;
    if(n%2) cout<<"0";
    else
    {
        a=5*2;
        ll ans=0;
        while(a<=n)
        {
            ans+=n/a;
            a*=5;
        }
        cout<<ans;
    }
}