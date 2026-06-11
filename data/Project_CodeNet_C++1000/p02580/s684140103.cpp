#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1,T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};
using Vote = pair<ll,ll>;
using Unordered_map = unordered_map<Vote, int, pair_hash>;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)
#define showvec(arr,a,b) for(ll i=a;i<b;i++) cout<<arr[i]<<" ";
#define read_input(arr,a,b) for(ll i=a;i<b;i++) cin>>arr[i];
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
#define SmooothOperatorrrrr()                 \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                    \
    cout.tie(0);                   
#define deci(n) cout<<fixed<<setprecision(n)
const int mod=998244353;
const int mod2=1000000007;
#define M_PI 3.14159265358979323846
#define LL_MAX 9223372036854775807
#define MAXN 2000001
/**************************************************************************************************/
int main()
{
    SmooothOperatorrrrr();
    ll h,w,m;cin>>h>>w>>m;
    ll M=m;
    unordered_map<ll,int> bombs;
    vector<ll> row(h);
    vector<ll> col(w);
    while(m--)
    {
        ll x,y;cin>>x>>y;
        x--;y--;
        ll val=x*1e9+y;
        bombs[val]=1;
        row[x]++;
        col[y]++;
    }
    ll max1=0;
    ll max2=0;
    FOR(i,0,h)
        max1=max(max1,row[i]);
    FOR(i,0,w)
        max2=max(max2,col[i]);
    vll v1,v2;
    FOR(i,0,h)
    {
        if(row[i]==max1)
            v1.pb(i);
    }
    FOR(i,0,w)
    {
        if(col[i]==max2)
            v2.pb(i);
    }
    int ok=0;
    FOR(i,0,v1.size())
    {
        FOR(j,0,v2.size())
        {
            ll val=v1[i]*1e9+v2[j];
            if(bombs.find(val)==bombs.end())
            {
                ok=1;
                break;
            }
        }
    }
    if(ok)
        cout<<max1+max2<<endl;
    else
        cout<<max1+max2-1<<endl;
}       