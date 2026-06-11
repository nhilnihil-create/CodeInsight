#include<iostream>
#include <cstddef>
#include<set>
#include<stack>
#include <deque>
#include<queue>
#include<utility>
#include<vector>
#include<map>
#include<cmath>
#include<cstring>
#include<bitset>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#define  ll  long long
#define ull unsigned long long
#define  sl(a)  scanf("%lld",&a)
#define  si(a)  scanf("%d",&a)
#define mem(n,m) memset(n,m,sizeof(n))
#define PI acos(-1)
#define pb    push_back
#define pf    push_front
#define vll   vector<ll>
#define pll   pair<ll,ll>
#define mp  make_pair
#define vpll vector< pair <ll,ll> >
#define vplpll vector<pair<ll,pair<ll,ll> > >
#define mp make_pair
#define all(v) v.begin(),v.end()
#define S(X) ( (X) * (X) )
#define forab(i, a, b) for(i = a; i <= b; i++)
#define forn(i, n) for(i = 0; i < n; i++)
#define print(a,b) printf("Case %lld: %lld\n",a,b)
using namespace std;
ll powd(ll a,ll b){if(b==1){return a;}if(b%2==1){return powd(a,b-1)*a;}else{ll x=powd(a,b/2); return x*x;}}
ll powm(ll a,ll b,ll m){if(b==0){return 1;}if(b==1){return a%m;}if(b%2==1){return ((powm(a,b-1,m)%m)*(a%m))%m;}else{ll x=powm(a,b/2,m); return ((x%m)*(x%m))%m;}}
ll gcd(ll a,ll b){if(a==0){return b;}return gcd(b,a%b);}
typedef multiset<ll> mlset;
typedef set<ll> mset;
typedef struct node* pnode;
ll a[200005],b[200005];
int main()
{
    ll n,m,k;
    sl(n);
    sl(m);
    sl(k);
    for(ll i=1;i<=n;i++)
    {
        sl(a[i]);
        a[i]=a[i]+a[i-1];
    }
    for(ll j=1;j<=m;j++)
    {
        sl(b[j]);
        b[j]=b[j-1]+b[j];
    }
    ll ans=0,j=m;
    for(ll i=0;i<=n;i++)
    {
        if(a[i]>k)
            break;
        while(b[j]+a[i]>k)
        {
            j--;
        }
        ans=max(ans,i+j);
    }
    cout<<ans<<endl;
    return 0;
}