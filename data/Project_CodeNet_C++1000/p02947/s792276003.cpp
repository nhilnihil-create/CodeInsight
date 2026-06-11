#pragma GCC optimize("Ofast")
/*#pragma GCC target("avx,avx2,fma")
#pragma GCC target ("sse4")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld double 
#define rep(i,a,b) for(ll i=a; i<b; ++i)
#define BOOST std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define all(v) v.begin(),v.end()
#define sl(a) a.size()
#define mod 1000000007 
#define lcm(a,b) (a*b)/__gcd(a,b)
#define MAX1 100006
#define f first
#define s second
#define pi 2*acos(0.0)
bool isPowerOfTwo (int x) {  return x && (!(x&(x-1)));  }
void solve()
{
    ll n; cin>>n;
    map<vector<ll>,ll> mp;
    rep(i,0,n)
    {
        string str;  cin>>str;
        vector<ll> freq(26,0);
        rep(j,0,sl(str)) freq[str[j]-'a']++;
        mp[freq]++;
    }
    ll ans=0;
    for(auto i: mp)
    {
        ans+=((i.s)*(i.s-1))/2;
    }
    cout<<ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt","r",stdin);
    //for getting error from error.txt
    freopen("error.txt", "w", stderr);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
    #endif
    BOOST
    int T=1;  //cin>>T;
    while(T--) solve();
    cerr<<"Time taken : "<<fixed<<setprecision(5)<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<"\n";
    cerr<<"My CLOCKS_PER_SEC= "<<CLOCKS_PER_SEC<<"\n";
    return 0;
}