//From Naruto to Hokage
//#include <RJ>
#include<bits/stdc++.h>
using namespace std;

#define ll          long long
#define pb          push_back
#define eb          emplace_back
#define endl        '\n'
#define mii         map<ll,ll>
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll)x.size()
#define hell        1000000007
#define INF         (1ll<<60)
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define rrep(i,a,b)  for(ll i=a;i>=b;i--)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
const int N=100005;
void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll w=0,b=0;
    rep(i,0,2*n-1){
        if(s[i]=='W') w++;
        else b++;
    }
    if(s[0]=='W' || s[2*n-1]=='W'){cout<<"0";return;}
    // if(w!=b) {cout<<0;return;}
    ll k=1;
    rep(i,2,n) k=(k*i)%hell;
    ll ans=k;
    ll arr[2*n];
    arr[0]=0;
    rep(i,1,2*n-1){
        if(s[i]==s[i-1]) arr[i]=!arr[i-1];
        else arr[i]=arr[i-1];
    }
    ll cl=0;
    rep(i,0,2*n-1){
        if(arr[i]){
            ans=(ans*cl)%hell;
            cl--;
        }
        else cl++;
    }
    if(cl==0)
    cout<<ans;
    else cout<<0;
}
signed main()
{
    ios
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--){
        solve();
    }
    time
    return 0;
}