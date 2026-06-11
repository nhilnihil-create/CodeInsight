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
    #define mod   998244353
    #define ld long double
    #define read(t) ll t;cin>>t;
    #define all(x) x.begin(),x.end()
    #define fi first
    #define se second
    #define endl "\n"
    #define pii pair<ll,ll>
    #define what_is(x) cerr << #x << " is " << x << endl;
    #define time cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    const double pi=3.14159265358979323846264;
    typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
    typedef tree<long long,null_type,greater<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set1;

/**********************************************************************************************************************/

signed main()/*Check flow...question galat mat padhna */
{
    fast;   
    ll n,m;
    cin>>n>>m;
    priority_queue<ll>x;
    For(i,n)
    {
        ll a;
        cin>>a;
        x.push(a);
    }
    For(i,m)
    {
        ll a=x.top();
        x.pop();
        a=a/2;
        x.push(a);
    }
    ll ans=0;
    while(!x.empty())
    {
        ans+=x.top();
        x.pop();
    }
    cout<<ans<<endl;
}      