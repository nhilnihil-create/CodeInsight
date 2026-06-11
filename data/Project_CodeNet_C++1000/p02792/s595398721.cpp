#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
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
const ll INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
const ll mod = 998244353;
const ll MAX = 1100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[8] ={1,0,-1,0,1,-1,1,-1};
ll dy[8] ={0,1,0,-1,1,-1,-1,1};
 
template<class T> 
inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> 
inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }




void solve(){
    ll n;
    cin>>n;
    string s=to_string(n);
    ll k=s.size();
    ll ans=0;
    ll b[20];
    b[0]=1;
    rep(i,7) b[i+1]=b[i]*10;
    rep2(i,1,n+1){
        string t=to_string(i);
        ll m=t.size();
        if(t[m-1]=='0'||t[0]=='0') continue;
        if(t[m-1]==t[0]) ans++;
        ll num=i;
        if(m==1){
            t=to_string(i*10+i);
            num=i*10+i;
        }
        else if(i>99){
            t=to_string(i/b[m-1]*10+i%10);
            num=i/b[m-1]*10+i%10;
        }
        m=2;
        // cout<<"t:"<<t<<"//";

        rep(j,k-2){
            ans+=b[j];
        }

        if(t[m-1]<s[0]){
            // cout<<"paturn a ";
            ans+=b[k-2];

        }
        else if(t[m-1]==s[0]){
            // cout<<"paturn b"<<i<<" ";
            ll a=(num%10)*b[k-1]+num/10;
            // cout<<"a:"<<a<<" ";
            if(a<=n){
                ans++;
                ans+=abs((n-a)/10);
            }
        }
        else{
            // cout<<"paturn c"<<i<<" ";
        }
        // cout<<i<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    
     

    solve(); 


    return 0;
}
