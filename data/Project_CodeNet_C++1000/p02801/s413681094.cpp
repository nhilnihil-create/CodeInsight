    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    #include <ext/pb_ds/detail/standard_policies.hpp>
    using namespace std;
    using namespace __gnu_pbds;
    #define ll long long
    #define int long long
    #define pb push_back
    #define For(i,n) for(ll  i=0;i<n;i++)
    #define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) ;clock_t clk = clock();
    #define f(a,b,c) for(ll a=b;a<c;a++)
    #define ld long double
    #define read(t) ll t;cin>>t;
    #define all(x) x.begin(),x.end()
    #define fi first
    #define se second
    #define pii pair<ll,ll>
    #define endl "\n"
    #define what_is(x) cerr << #x << " is " << x << endl;
    #define time cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    const double pi=3.14159265358979323846264;
    typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
    typedef tree<long long,null_type,greater<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set1;
/*.....................................................................................................................*/

    ll mod =(ll)1e9+7;
    ll add(ll x,ll y) {return (x+y)%mod;}
    ll mult(ll x, ll y){return ((x%mod )* (y%mod)) % mod;}
    long long binpow(long long x, long long p) 
    {
        if (p == 0) return 1;
    	if (p == 2 || (p & 1)) return mult(x, binpow(x, p - 1));
    	return binpow(binpow(x, p / 2), 2);
    }
    ll modinv(ll a) {return binpow(a,mod-2);}

    // bool check(ll y){}
    ll binsearch(ll l,ll r)
    {
        // while(r-l>1)
        // {
        //     ll mid=(l+r)/2;
        //     if(check(mid))l=mid;
        //     else r=mid;
        // }
        return l;
    }
    const ll man=(ll)1e5+5;
    // vector<ll>adj[man];
    // bool vis[man][man];
    // ll d[man],depth[man],par[man];
    // void addedge(ll u,ll v){adj[u].pb(v);adj[v].pb(u);}
    ll dx[4]={1,-1,0,0};ll dy[4]={0,0,1,-1};
/*........................................................................................................................*/

signed main()/*Check flow...question galat mat padhna */
{
    fast;
    char c;
    cin>>c;
    cout<<(char)(c+1)<<endl;
}