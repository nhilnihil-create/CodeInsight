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
typedef priority_queue<ll,vector<ll>,greater<ll>> PQIG;
typedef priority_queue<P,vector<P>,greater<P>> PQPG;
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
    vec ra(n+1); // 数字はどのIndexにあるか 
    rep(i,n) ra[a[i]]=i;
    // これ以降aは使わない

    ll ans=0;

    multiset<int> s; // ｘより小さいもののindexが入っている
    s.insert(-1); s.insert(n); // ストッパー
    s.insert(-1); s.insert(n); // ストッパー
    s.insert(ra[n]);
    for(int d=n-1;d>=1;d--){ // 1から小さい順にみてみる
        int i=ra[d]; // dのindexを代入
        auto it=s.lower_bound(i); // indexでみてsのiよりも大きな場所である最小を求める（ｄ＝＝1ならnとなる）
        int r=*it;
        it++;
        int R=*it;
        it--;
        it--; // iよりも大きな場所である最小から-1すると、小さな最大が出る
        int l=*it;
        it--;
        int L=*it;
        ll memo=0;
        if(r!=n&&l!=-1){
            ans+=d*(r-i)*(l-L);
            ans+=d*(i-l)*(R-r);
            memo+=d*(r-i)*(l-L)+d*(i-l)*(R-r);
        }
        else if(l==-1){
            ans+=d*(i+1)*(R-r);
            memo+=d*(i+1)*(R-r);
        }
        else if(r==n){
            ans+=d*(n-i)*(l-L);
            memo+=d*(n-i)*(l-L);
        }
        // cout<<l<<" "<<r<<" "<<memo<<endl;
        s.insert(i);
    }
    cout<<ans<<endl;
    
}