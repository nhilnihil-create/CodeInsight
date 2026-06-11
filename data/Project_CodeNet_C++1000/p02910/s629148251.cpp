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
    string s;
    cin>>s;
    ll ans=0;
    For(i, s.length())
    {
        if(i%2==1)
        {
            if(s[i]=='R')ans++;
        }
        else 
        {
            if(s[i]=='L')ans++;
        }
    }
    if(ans)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}      