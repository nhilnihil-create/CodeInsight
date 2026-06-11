#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>pll;

const int N=1e7;

ll v[N+10];

ll a[N+10];


bool compare(string  &a, string &b)
{
     string f=a+b,c=b+a;

     return f<c;
}

int main()
{
    ll n;

    cin>>n;

    ll ara[n+10];

    for(ll i=0;i<n;i++)
    {
        cin>>ara[i];
    }

    sort(ara,ara+n);
    
    double sum=0,ans=0;

    sum=(ara[0]+ara[1])/2.0;

    for(ll i=2;i<n;i++)
    {
        sum=(sum+ara[i])/2.0;
    }

    cout<<sum<<endl;

}






