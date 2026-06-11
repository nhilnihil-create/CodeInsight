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
const int N=3e5+5;
int a[N];
int c[N];
int32_t main(){
    int n;
    cin>>n;
    forn(i,n){
        cin>>a[i];
        c[a[i]]++;
    }
    multiset<int,greater<int>> s;
    forn(i,n+1)if(c[i])s.insert(c[i]);
    int sum=n;
    for(int k=1;k<=n;++k){
        while(!s.empty()&&(*s.begin()>sum/k)){
            int v=*s.begin();
            s.erase(s.begin());
            if(v>1)s.insert(v-1);
            sum--;
        }
        cout<<(sum/k)<<'\n';
    }
    return 0;
}