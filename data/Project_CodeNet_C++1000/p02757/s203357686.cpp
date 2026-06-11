#include<bits/stdc++.h>
#include<string.h>
#define ll long long
#define pf printf
#define sf scanf
#define ff first
#define ss second
#define clr clear()
#define sz size()
#define pb push_back
#define mk make_pair
#define pi acos(-1)
#define inf 200000000
//#define mod 1000000007
#define ull unsigned long long int
#define f(i,k,n) for(i=k;i<n;i++)
#define fr(i,n,k) for(i=n;i>=k;i--)
#define ent(a) scanf("%lld",&a)
#define ent2(a,b) scanf("%lld%lld",&a,&b)
#define ent3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define mem(a) memset(a,0,sizeof(a))
#define vec(v,s) vector<ll>v[s]
#define arr(a,s) ll a[s];
/*#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
//knight and king//
int dr[]= {2,2,-2,-2,1,-1,1,-1};
int dc[]= {1,-1,1,-1,2,2,-2,-2};
int dr1[]= {0,0,1,1,1,-1,-1,-1};
int dc1[]= {1,-1,1,0,-1,0,1,-1};
int dr2[]= {0,0,1,-1};
int dc2[]= {1,-1,0,0};
////////////////////////////
using namespace std;
#define ma 200005

ll a[ma],pr[ma],fr[ma];

ll bigmod(ll n,ll p,ll mod)
{
    if(p==0)return 1;
    ll x=bigmod(n,p/2,mod);
    x=(x*x)%mod;
    if(p%2==1)x=(x*n)%mod;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,q,i,j,m,g,r,p;
    while(cin>>n>>p)
    {
        string s;cin>>s;
        pr[0]=1;
        for(i=1;i<=n;i++)
        {
            pr[i]=(pr[i-1]*10)%p;
        }

        for(i=0;i<s.sz;i++)
        {
           a[i+1]=a[i]+pr[n-i]*(s[i]-'0');
           a[i+1]%=p;
        }

       // for(i=0;i<=n;i++)cout<<a[i]<<" ";
        //cout<<endl;
        ll ans=0;

       /* for(i=1;i<=n;i++)
        {
            for(j=i-1;j>=0;j--)
            {
             ll x=(a[i]-a[j]+p)%p;
             x=x*bigmod(pr[i],p-2,p);
             x%=p;
             ll y=bigmod(p,p-2,p);
             ll r=(x*y)%p;
             if(r*p==x)
             {
                 if(a[i]!=a[j])
                 cout<<a[i]<<" "<<a[j]<<" "<<j+1<<" "<<i<<endl;
                 ans++;
             }

            }
        }*/

       /* for(i=0;i<n;i++)
        {
            ll s1=0;
            for(j=i;j<n;j++)
            {
                s1=s1*10+(s[j]-'0');
                s1%=p;
                bool f=0;
                if(s1==0)
                {
                    f=1;
                    ans++;
                    if(a[i]!=0)
                    cout<<i<<" "<<j<<" "<<a[i]<<" "<<a[j+1]<<endl;
                }
               // if(f==0&&a[i]==a[1+j])cout<<a[i]<<" "<<a[j+1]<<" "<<i<<" "<<j<<" "<<"suck"<<endl;
            }
        }
        cout<<ans<<endl;*/

        ll ans1=0;
        fr[0]=1;

        if(p==2||p==5)
        {
            for(i=0;i<s.sz;i++)
            {
                ll r=s[i]-'0';
                if(r%p==0)ans1+=(i+1);
            }
            cout<<ans1<<endl;
            continue;
        }

        for(i=1;i<=n;i++)
        {
            fr[a[i]]++;
        }

        for(i=0;i<p;i++)
        {
            ll r=fr[i]*(fr[i]-1);
            r/=2;
            ans1+=r;
        }

        cout<<ans1<<endl;


    }
    return 0;
}
