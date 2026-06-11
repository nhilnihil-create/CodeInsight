#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
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
const int N=1e5+5;
int32_t main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<"No\n";
    }else if(n&1){
        cout<<"Yes\n";
        for(int i=2;i<=n;i+=2)cout<<"1 "<<i<<'\n';
        for(int i=2;i<=n;i+=2)cout<<i<<' '<<i+n+1<<'\n';
        for(int i=3;i<=n;i+=2)cout<<"1 "<<i<<'\n';
        for(int i=3;i<=n;i+=2)cout<<i<<' '<<i+n-1<<'\n';
        cout<<3+n<<' '<<1+n<<'\n';
    }else{
        int ok=0;
        for(int x=1;!ok&&x<n;++x){
            int y=(n+1)^x;
            if(y>=1&&y<n){
                ok=1;
                cout<<"Yes\n";
                cout<<x<<' '<<n<<'\n';
                cout<<y<<' '<<n+n<<'\n';
            }
        }
        if(!ok)cout<<"No\n";
        else{
            for(int i=2;i<=n-1;i+=2)cout<<"1 "<<i<<'\n';
            for(int i=2;i<=n-1;i+=2)cout<<i<<' '<<i+n+1<<'\n';
            for(int i=3;i<=n-1;i+=2)cout<<"1 "<<i<<'\n';
            for(int i=3;i<=n-1;i+=2)cout<<i<<' '<<i+n-1<<'\n';
            cout<<3+n<<' '<<1+n<<'\n';
        }
    }

    return 0;
}