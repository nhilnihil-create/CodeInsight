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
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef priority_queue<ll> PQI;
typedef priority_queue<P> PQP;
typedef vector<vector<P>> pvec;
typedef vector<vector<ll>> vvec;
typedef vector<ll> vec;
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
    
    int n;
    cin>>n;
    vector<int> a(n);
    REP(i,n) cin >> a[i];
    bool flag=false;
    map<int,int> mp;
    rep(i,n){
        mp[a[i]]++;
    }
    for(auto &x : mp){
        if(x.fs==0&&x.sc==n) flag=true;
    }
    ll memo=0;
    for(auto &x : mp){
        if(x.fs==0&&x.sc==n/3) memo++;
        if(x.sc==n*2/3) memo++;
    }
    if(memo==2) flag=true;
    memo=0;
    ll h=0;
    for(auto &x : mp){
        h^=x.fs;
        if(x.sc==n/3) memo++;
    }
    if(memo==3&&h==0) flag=true;

    if(flag){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    

    
}