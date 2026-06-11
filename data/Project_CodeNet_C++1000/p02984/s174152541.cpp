#pragma GCC optimize("Ofast")
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
void solve()
{
    ll n,x1,temp=0;  cin>>n;
    ll arr[n];
    rep(i,0,n)  cin>>arr[i];
    

    for(ll j=n-2; j>=0; --j) temp+=((j&1?1:-1)*arr[j]);
    x1=(arr[n-1]-temp)/2;
    cout<<2*x1<<" ";
    vector<ll> vec(n,0);
    vec[0]=2*x1;
    for(ll i=1; i<n; ++i) 
    {
        vec[i]=(arr[i-1]-(vec[i-1]/2));
        vec[i]*=2;
        cout<<vec[i]<<" ";  
    }
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
    cerr<<"Time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<"\n";
    cerr<<"My CLOCKS_PER_SEC= "<<CLOCKS_PER_SEC<<"\n";
    return 0;
}
