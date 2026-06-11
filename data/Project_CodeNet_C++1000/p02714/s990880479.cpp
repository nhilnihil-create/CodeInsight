#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define ppll pair<ll,pll>
#define pdd pair<double,double>
#define vii vector<int>
#define vll vector<ll>
#define mat vector<vector<ll>>
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define sz(x) (ll) (x).size()
#define pq priority_queue<ll>
#define pqg priority_queue<ll,vector<ll>,greater<ll>>
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end())
#define int ll
// #define ll int
using namespace std;
const ll INF = 1 << 29;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
const int MAX_V = 500;
// const ll mod = 998244353;
const ll MAX = 2100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[8] ={1,0,-1,0,1,-1,1,-1};
ll dy[8] ={0,1,0,-1,1,-1,-1,1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }






void solve() {
    ll n;
    string s;
    cin>>n>>s;
    ll a[4010]={},b[4010]={},c[4010]={};
    repr(i,n){
        a[i]=a[i+1];
        b[i]=b[i+1];
        c[i]=c[i+1];
        if(s[i]=='R') a[i]++;
        else if(s[i]=='G') b[i]++;
        else c[i]++;
    }

    ll ans = 0;

    rep(i,n){
        rep2(j,i+1,n){
            ll x = 0;
            if(s[i]==s[j]) continue;
            if(s[i]=='R'||s[j]=='R') x+=1;
            if(s[i]=='G'||s[j]=='G') x+=2;
            if(s[i]=='B'||s[j]=='B') x+=4;
            char now;
            ll cnt=0;
            if(x==6) now='R',cnt=a[j+1];
            else if(x==3) now='B',cnt=c[j+1];
            else now='G',cnt=b[j+1];

            if(j + (j-i) < n){
                if(s[j+(j-i)] == now){
                    cnt--;
                }
            }
            ans += cnt;
        }
    }
    cout<<ans<<endl;

}


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);


    ll t=1;
    
    // cin>>t;

    rep(i,t){
        solve(); 
    }

    return 0;
}
