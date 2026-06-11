#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define rep_start(a,i,n) for(ll i=a;i<=n;i++)
#define rev(i,n) for(ll i=n-1;i>=0;i--)
#define rev1(i,n) for(ll i=n;i>0;i--)
#define sz(a) int((a).size())
#define all(c) c.begin(),c.end()
#define tr(c,i) for(typeof(c).begin() i+=c.begin; i!=c.end(); i++)
#define present(c,x) (c.find(x)!=c.end())
#define cpresent(c,x) (find(all(c),x)!=c.end())
#define pb push_back
#define F first
#define S second
#define INF INT_MAX
#define mod 1000000007
#define print1(a) cout<<a<<"\n";
#define print2(a,b) cout<<a<<" "<<b<<"\n";
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n";
#define mt make_tuple
#define eb emplace_back

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef tuple<int,int,int> State;

void solve(){
    ll k,a,b,tmp;cin>>k>>a>>b;
    if(a%k!=0) tmp=a/k*k+k;
    else tmp=a;
    if(tmp>=a && tmp<=b) cout<<"OK";
    else cout<<"NG";
}

signed main() {
    // your code goes here
    IOS
    ll t=1;
    //cin>>t;
    rep1(i,t){
        solve(); 
    }
    return 0;
}