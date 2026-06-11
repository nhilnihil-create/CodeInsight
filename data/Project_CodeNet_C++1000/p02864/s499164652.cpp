#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sz(a)((int)(a).size())
#define sqr(x) ((x)*(x))
struct init{init(){cin.tie(0);iostream::sync_with_stdio(0);cout<<fixed<<setprecision(10);cerr<<fixed<<setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());const int D=4,dx[]={+1,0,-1,0},dy[]={0,+1,0,-1};

const int N=303,OO=1e18;
int a[N];
int dp[N][N][N];
int mn[N][N][N];
int kp[N][N][N];
int32_t main(){
    int n,k;
    cin>>n>>k;
    vector<int> al;
    for(int i=1;i<=n;++i){cin>>a[i];al.pb(a[i]);}
    al.pb(0);
    sort(al.begin(), al.end());
    al.resize(unique(al.begin(), al.end())-al.begin());
    forn(i,N)forn(j,N)forn(v,N)dp[i][j][v]=mn[i][j][v]=kp[i][j][v]=OO;
    dp[0][0][0]=mn[0][0][0]=0;
    forn(v,N)kp[0][0][v]=0;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=k;++j){
            for(int v=0;v<sz(al);++v){
                int val=al[v];
                int ch=val!=a[i];
                if(j||!ch)dp[i][j][v]=min(mn[i-1][j-ch][v],kp[i-1][j-ch][v]+val);
                mn[i][j][v]=dp[i][j][v];
                kp[i][j][v]=dp[i][j][v]-val;
                if(v)upn(kp[i][j][v],kp[i][j][v-1]);

            }
            for(int v=sz(al)-2;v>=0;--v)upn(mn[i][j][v],mn[i][j][v+1]);
        }
    }
    int ans=OO;
    forn(j,k+1)forn(v,sz(al))upn(ans,dp[n][j][v]);
    cout<<ans<<'\n';

    return 0;
}