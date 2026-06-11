#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
// #define pii pll
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
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}mt19937 rng(12);const int D=4,dx[]={+1,0,-1,0},dy[]={0,+1,0,-1};

const int N=1<<18;
int a[N],u[N];
int32_t main(){
    int n;cin>>n;
    n=1<<n;
    forn(i,n)cin>>a[i];
    sort(a,a+n);
    reverse(a,a+n);
    vector<int> v={a[0]};
    u[0]=1;
    while(sz(v)<n){
        int j=0,c=sz(v);
        forn(i,n){
            if(!u[i]&&a[i]<v[j]){
                u[i]=1;
                v.pb(a[i]);
                if((++j)==c)break;
            }
        }
        if(j<c){
            cout<<"No\n";
            return 0;
        }
        sort(v.begin(), v.end());reverse(v.begin(), v.end());
    }
    cout<<"Yes\n";

    return 0;
}
