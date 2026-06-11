#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define vi vector<ll>
#define vpi vector<pair<ll,ll> >
#define mpi map<ll,ll>
#define  si set<ll>
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define reP(i,a,n) for(ll i=a;i<=n;i++)
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define st string
#define sz size()
#define case(i,n) Case<<" "<<i<<": "<<n<<endl;
#define tc ll t;cin>>t;while(t--)
int main()
{
    ll n,m;cin>>n;
    ll x,y;
    ll mi=1000000000000;
    ll d=sqrt(n);
    for(ll i=1;i<=d;i++)
    {
        if(n%i==0)
        {
            ll m=abs(i-(n/i));
            if(m<mi)
            {
                x=i;
                y=n/i;
            }
        }
    }
    cout<<(x-1)+(y-1)<<endl;
}
