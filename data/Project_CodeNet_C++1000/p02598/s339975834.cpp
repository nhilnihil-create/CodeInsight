#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg puts("It's Just Begining.Wait For The End!!!!!\n")
#define CHECK(x) cout << (#x) << " is " << (x) <<"\n";
#define endl printf("\n")
typedef pair<ll,ll> pii;
#define pb push_back
#define ms(a,b) memset(a, b, sizeof(a))
#define in(x) scanf("%lld",&x)
#define out(x) printf("%lld",x)
#define X first
#define Y second
#define sps printf(" ")
#define dou(x) cout<<fixed<<setprecision(6)<<x
#define all(v) v.begin(),v.end()
#define dis(it,it1) distance(it,it1)+1
#define MAX 200005
#define INF 1000000000
#define MOD 1000000007
#define print(cs) printf("Case %lld: ",cs)
#define Yesno(ok) if(ok)puts("YES");else puts("NO")
#define yesno(ok) if(ok)puts("Yes");else puts("No")
ll lcm(ll a,ll b)
{
    return ((a*b)/__gcd(a,b));
}
vector<ll>v;
ll mov(ll val,ll n)
{
    ll i,j,k,l,r=0;
    for(i=0; i<n; i++)
    {
        k=ceil(v[i]/(double)val)-1;
        k=max(k,0LL);
        r+=k;
    }
    return r;
}
int main()
{
    ll i,j,k,l,n,m,r,lo=1,hi=0,mid;
    in(n);
    in(k);
    v.resize(n);
    for(i=0; i<n; i++)
    {
        in(v[i]);
        hi=max(hi,v[i]);
    }
    ll ans;
    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;
        if(mov(mid,n)<=k)
        {
            ans=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    out(ans);
    endl;
}
