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
    rep(i,0,n-1){
        rep(j,i+1,n-1){
            ll x=i^j;
            ll k=0;
            while((x&(1<<k))==0) k++;
            cout<<k+1<<" ";
        }
        cout<<endl;
    }   
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