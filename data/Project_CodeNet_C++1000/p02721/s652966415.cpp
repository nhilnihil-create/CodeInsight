#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define inf 1000000000
#define ninf -1000000000
#define endl '\n' 
#define she_told_me_dont_worry ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// Use cout.flush() for interactive problems.
// Use this for increased stack size: g++ -o a.exe -Wl,--stack=256000000 -O2 source.cpp
inline long long  MAX2(long long  a, long long int b){return (a)>(b)?(a):(b);}
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN2(long long  a, long long  b){return (a)<(b)?(a):(b);}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector< ii > vii;
const int N = 2e5+5;
ll n, k, c;
string s;
ll dpf[N], dpb[N];
ll comp_front(ll i)
{
    if(i >= n) return 0;
    if(dpf[i] != -1) return dpf[i];
    ll ans = 0;
    //keep
    if(s[i] == 'o')
        ans = 1 + comp_front(i+c+1);
    //dont keep
    ans = MAX2(ans, comp_front(i+1));
    return dpf[i] = ans;
}
ll comp_back(ll i)
{
    if(i < 0) return 0;
    if(dpb[i] != -1) return dpb[i];
    ll ans = 0;
    //keep
    if(s[i] == 'o')
        ans = 1 + comp_back(i-c-1);
    // dont keep
    ans = MAX2(ans, comp_back(i-1));
    return dpb[i] = ans;
}
int main()
{
    she_told_me_dont_worry
    cin>>n>>k>>c;
    int i;
    cin>>s;
    if(c == 0)
    {
        vi out;
        FOR0(i, n) 
            if(s[i] == 'o')
                out.pb(i);
        if(out.size() <= k) 
        {
            int si = out.size();
            FOR0(i, si) cout<<out[i]+1<<endl;
        }
        else
            cout<<endl;
        return 0;
    }
    int num[n+5] = {};
    FOR0(i, n+2)
    {
        dpf[i] = -1;
        dpb[i] = -1;
    }
    FOR(i, 1-c, n)
    {
        ll l = 0, r = 0;
        if(i > 0) l = comp_back(i-1);
        if(i+c < n) r = comp_front(i+c);
        if(l + r >= k) 
        {
            int pos = MAX2(i, 0);
            num[pos]++;
            if(i+c < n)
                num[i+c]--;
        }
    }
    FOR(i, 1, n) 
        num[i] += num[i-1];
    FOR0(i, n) if(s[i] == 'x') num[i]++;
    FOR0(i, n)
    {
        if(!num[i]) cout<<i+1<<endl;
    }
    cerr <<endl<< "Time elapsed : " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';
}