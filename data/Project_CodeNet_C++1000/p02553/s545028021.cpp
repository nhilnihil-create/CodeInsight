#pragma GCC optimize("Ofast")
#pragma GCC optimize("-ffloat-store")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
#define debug(val) printf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define mod 1000000007
#define inf  1e18
#define ps(x,y)   fixed<<setprecision(y)<<x
#define clr(val) memset(val,0,sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e3 + 10;
int main() 
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
    FIO;
    ll a,b,c,d;
    cin >>a >>b>>c>>d;
    ll ans = max({a*d,a*c,b*c,b*d});
    cout<<ans<<endl;
return 0;   
}