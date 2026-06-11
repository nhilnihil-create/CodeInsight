// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x) cout << #x << ' ' << '=' << ' ' << (x) << endl;
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef vector<ll> vec;
typedef vector<P> pvec;
typedef vector<vector<ll>> vvec;
typedef vector<vector<P>> pvvec;
typedef priority_queue<ll> PQI;
typedef priority_queue<P> PQP;
const vector<int> dx = {0, -1, 0, 1, 1, 1, -1, -1};
const vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
const int MOD = (1000000007);
// const int MOD = (998244353);
// const int INF = (1 << 30);
const int INF = (1LL << 60);
const double EPS = (1 >> 30);
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    //---------------------------------------------
    
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    reverse(all(s));
    vec a(n+1,INF); a[0]=0;
    rep(i,n){
        int b=0;
        if(s[i]=='1') continue;
        for(int j=1;j<=m;j++){  
            if(range(i+j,0,n+1)){
                if(s[i+j]=='1') continue;
                chmin(a[i+j],a[i]+1); 
                chmax(b,i+j);
            }
        }
        if(b!=0)i=b-1;
    }
    // rep(i,n+1) debug(a[i]);
    if(a[n]==INF) cout<<-1<<endl;
    else{
        vec ans;
        map<int,int> mp;
        rep(i,n+1){
            if(s[i]=='1') continue;
            chmax(mp[a[i]],i);
        }
        for(auto x:mp) ans.pb(x.sc);
        reverse(all(ans));
        rep(i,ans.size()-1){
            cout<<ans[i]-ans[i+1]<<endl;
        }
    }
    
}
