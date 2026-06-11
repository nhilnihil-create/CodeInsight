#include<bits/stdc++.h>
#define ll long long int
#define Y printf("YES\n")
#define N printf("NO\n")
#define mp make_pair
#define pb push_back
#define tp make_tuple
#define sc(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define pr(a) printf("%lld\n",a)
using namespace std;
#define mod 1000000007

bool chk_bit(ll n,ll k) // check whether 0 or 1
{
    return n & (1LL << k);
}

int main()
{
    ll n,i,j,x=0,y=0,d;

    cin>>n;

    ll a[n+5];

    for(i=0; i<n; i++)cin>>a[i];

    ll sum=0;

    for(i=0; i<64; i++)
    {

        x=0,y=0;

        for(j=0; j<n; j++)
        {

            if(chk_bit(a[j],i))x++;
            else y++;
        }

        d=(x*y)%mod;

        ll dd=(1LL << i)%mod;

        ll kk=(d*dd)%mod;

        sum+=kk;

        sum=sum%mod;
    }

    cout<<sum%mod<<endl;


}