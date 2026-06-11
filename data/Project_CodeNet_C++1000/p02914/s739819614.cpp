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

const int N=1e5+5,B=60;
int a[N],c[B],b[B];
void add(int x){
    for(int i=B-1;i>=0;--i){
        if(x>>i&1){
            if(b[i]==-1){
                b[i]=x;
                break;
            }else x^=b[i];
        }
    }
}
int32_t main(){
    int n;
    cin>>n;
    forn(i,n){
        cin>>a[i];
        forn(j,B)if(a[i]>>j&1)c[j]^=1;
    }
    int kek=0;
    forn(j,B){
        if(c[j]){
            kek+=1ll<<j;
            forn(i,n)if(a[i]>>j&1)a[i]^=1ll<<j;
        }
    }
    memset(b,-1,sizeof b);
    forn(i,n)add(a[i]);
    int kok=0;
    for(int i=B-1;i>=0;--i)
        if(b[i]!=-1&&!(kok>>i&1))
            kok^=b[i];
    cout<<kok+kek+kok<<'\n';
    return 0;
}
