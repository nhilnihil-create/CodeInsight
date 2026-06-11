#include<bits/stdc++.h>
using namespace std;
#define read FILE *fp;\
fp=freopen("testcase.txt","r",stdin);
#define ll long long
#define ull unsigned long long
#define sf(n) scanf("%lld",&n)
#define pf(n) printf("%lld ",n)
#define loop for(long long i=0;i<n;i++)
#define lp(b,n) for(long long i=b;i<=n;i++)
#define pb(n) push_back(n)
#define srt(v) sort(v.begin(),v.end())
#define rvs(v) sort(v.begin(), v.end(), greater<long long>());
#define F first
#define S second
#define mp(a,b) make_pair(a,b);
#define fio ios::sync_with_stdio(false); cin.tie(),cout.tie();
bool sortbysec(const pair<pair<ll,ll>,ll> &a,
               const pair<pair<ll,ll>,ll> &b)
{
    return (a.second < b.second);
}

string add(string st1,string st2)
{
    ll r=0;
    string ans;
    ans.resize(3000);
    for(ll i=2999; i>=0; i--)
    {
        ll x=st1[i]-'0';
        ll y=st2[i]-'0';
        ll z=x+y+r;
        if(z>=10)
        {
            r=1;
        }
        else
            r=0;
        ans[i]=(z%10)+'0';
    }
    //cout<<ans<<endl;;
    return ans;
}
ll p(ll x)
{
    return ((x%1000000007)*2)%1000000007;
}
//ll mat[1005][1005];
ll f(ll h,set<ll> s,ll ans)
{
    if(h<=1)
    {
        return ans;
    }
    cout<<ans<<endl;
    ll ans1,ans2,ans3,ans4;
    if(s.find(h-1)==s.end())
    {
        ans1=f(h-1,s,ans);
    }
    else
    {
        ans1=f(h-1,s,ans+1);
    }
    if(s.find(h-1)==s.end())
    {
        ans2=f(h-2,s,ans+1);
    }
    else
    {
        ans2=f(h-2,s,ans);
    }
    cout<<ans1<<" "<<ans2<<"t\n";
    return min(ans1,ans2);
}

//bool pr[200005];

//vector<ll> prime;
#define int long long

int gcdExtended(int a, int b, int *x, int *y);

// Function to find modulo inverse of a
int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);


    // m is added to handle negative x
    int res = (x%m + m) % m;
    return res;

}

// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

#undef int

//ll table[10000][10000]; //Create a 50*50 table with -1 in each cell
ll nCr(ll n,ll r)
{
    ll u=1;
    ll m=  998244353;
    for(ll i=0; i<r; i++)
    {
        u=(u*(n-i))%m;
    }
    ll d=1;
    for(ll i=1; i<=r; i++)
    {
        d = (d*i)%m;
    }

    return (u*modInverse(d,m))%m;
}
//ll ar[10000000+5];
//ll av[1000000+5];
ll Pow(ll a,ll b)
{
    if(b==0)
        return 1;
    if(a==0)
        return 1;
    // b--;
    ll an=1;
    while(b--)
    {
        an*=a;
    }
    return an;
}
ll sumofdig(ll x)
{
    ll s=0;
    while(x)
    {
        s+=x%10;
        x/=10;
    }
    return s;
}

//ll ar[700000+15];

#define pr pair< pair<ll,ll>, pair<ll,ll> >

int main()
{


    ll n;
    cin>>n;
    vector<ll> A,B,C;
    for(ll i=0;i<n-1;i++)
    {
        ll t;
        sf(t);
        A.pb(t);
    }
    ll ans=A[0]+A.back();
    for(ll i=0;i<n-2;i++)
    {
        ans+=min(A[i],A[i+1]);
    }
    cout<<ans<<endl;
}






