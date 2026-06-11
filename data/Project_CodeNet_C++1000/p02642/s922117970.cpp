#include<bits/stdc++.h>
#define ll                long long int
#define ld                long double
#define F                 first
#define S                 second
#define C                 continue
#define G                 goto done
#define pb                push_back
#define pf                push_front
#define ppb               pop_back
#define ppf               pop_front
#define sz                size()
#define pi                acos(-1.0)
#define mod               1000000007
#define maxe              *max_element
#define mine              *min_element
#define min3(a,b,c)       min(a,min(b,c))
#define max3(a,b,c)       max(a,max(b,c))
#define min4(a,b,c,d)     min(a,min(b,min(c,d)))
#define max4(a,b,c,d)     max(a,max(b,max(c,d)))
#define mem(a,b)          memset(a,b,sizeof(a))
#define all(a)            (a).begin(),(a).end()
#define gcd(a,b)          __gcd(a,b)
#define lcm(a,b)          ((a)*((b)/gcd(a,b)))
#define case(a)           cout<<"Case "<<(a)<<": "
#define point(a)          fixed<<setprecision(a)
#define get(a)            for(auto &x:a) cin>>x;
#define print(a)          for(auto x:a) cout<<x<<" "; cout<<endl;
#define uniq(a)           sort(all(a)); (a).erase(unique((a).begin(),(a).end()),(a).end())
#define big(a)            transform((a).begin(),(a).end(),(a).begin(),::toupper)
#define small(a)          transform((a).begin(),(a).end(),(a).begin(),::tolower)
#define ischar(a)         (('a'<=a&&a<='z')('A'<=a&&a<='Z'))
#define isvowel(a)        (a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U')
#define fast              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tc                int test; cin>>test; while(test--)
using namespace std;
int main()
{
    unordered_map<ll,ll>mp;
    map<ll,ll>keep;
    ll n; cin>>n; vector<ll>inp(n); get(inp);
    for(ll i=0;i<n;i++) keep[inp[i]]++;
    if(n==1)
    {
        cout<<"1"; return 0;
    }
    vector<ll>v;
    for(auto i:keep)
    {
        if(i.S==1) v.pb(i.F);
        else mp[i.F]++;
    }
    if(v.sz==0)
    {
        cout<<"0"; return 0;
    }
    ll c=0;
    vector<ll>vec(10000000);
    for(ll i=0;i<v.sz;i++)
    {
        ll k=v[i];
        for(ll j=1;j*j<=k;j++)
        {
            if(k%j==0)
            {
                ll x=k/j;
                ll y=j;
                if(vec[x]==1 || vec[y]==1 || mp[x]>=1 || mp[y]>=1) G;
            }
        }
        c++;
        done : 1;
        vec[k]=1;
    }
    cout<<c;
}














