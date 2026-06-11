#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define gcd __gcd
#define in(a) scanf("%d",&a)
#define in2(a,b) scanf("%d%d",&a,&b)
#define in3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define read(v,i,n) for(i=0;i<n;i++)in(v[i])
#define twod(mat,i,j,n,m) rep(i,n){rep(j,m)in(mat[i][j]);}
#define sc(ch) scanf("%c",&ch)
#define sstr(str) scanf("%s",str)
#define pr(n) printf("%d ",n)
#define out(n) printf("%d\n",n)
#define llin(a) cin >> a
#define llpr(a) cout << a << " "
#define llout(a) cout << a << endl
#define yes printf("YES\n")
#define no printf("NO\n")
#define lin printf("\n")
#define dbg(v,i,n) for(i=0;i<n;i++)pr(v[i]); lin
#define ck printf("continue\n")
#define all(vec) vec.begin(),vec.end()
#define asc(vec) sort(vec.begin(),vec.end())
#define lower(v,k) lower_bound(v.begin(),v.end(),k)-v.begin()
#define upper(v,k) upper_bound(v.begin(),v.end(),k)-v.begin()
#define tf(mytuple) get<0>(mytuple)
#define ts(mytuple) get<1>(mytuple)
#define tt(mytuple) get<2>(mytuple)
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vector<int> >
#define viii vector<pair<pair<int,int>,int> >
#define vvii vector<vector<pair<int,int> > >
#define lp(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) for(i=0;i<n;i++)
#define M 1000000007
#define S 60
#define N 200005  //check the limits, man
// read the constraint properly (ll vs int)
typedef long long int ll;
vector<vector<ll> > ad(S);
ll ar[S];
ll v[N];
ll maxxor(int n)
{
    ll x;
    int i,j,a,m;
    rep(i,n)
    {
        x=v[i];
        if(x>0)
            a=log2(x),ad[a].pb(x),ar[a]=max(ar[a],x);
    }
    for(i=S-1;i>=0;i--)
    {
        m=ad[i].size();
        rep(j,m)
        {
            x=(ar[i]^ad[i][j]);
            if(x>0)
                a=log2(x),ad[a].pb(x),ar[a]=max(ar[a],x);
        }
    }
    ll ans=0;
    for(i=S-1;i>=0;i--)
    {
        if((ar[i]^ans)>ans)
            ans^=ar[i];
    }
    return ans;
}
int main()
{
    int n,i,j,a;
    in(n);
    ll net=0;
    ll x,y;
    rep(i,n)
    {
        llin(v[i]);
        net^=v[i];
    }
    x=1;
    for(i=0;i<S;i++,x*=2)
    {
        if(net&x)
        {
            rep(j,n)
                if(v[j]&x)v[j]^=x;
        }
    }
    ll ans=maxxor(n);
    llout(net+2*ans);
}


