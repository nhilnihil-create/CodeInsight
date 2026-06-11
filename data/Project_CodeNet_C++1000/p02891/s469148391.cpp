#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sqr(x) ((x)*(x))
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}

int32_t main(){

    string s;
    int k;
    cin>>s>>k;
    char p='$';
    int ans=0,cur=0,ae=1;
    for(char c:s){
        ae&=c==s[0];
        if(c==p){
            cur++;
        }else{
            ans+=cur/2;
            cur=1;
        }
        p=c;
    }
    ans+=cur/2;
    if(s[0]!=p||k==1){
        cout<<ans*k<<'\n';
    }else{
        if(ae){
            int n=s.size();
            cout<<(n*k)/2<<'\n';
        }else{
            int cu=0;
            for(char c:s){
                if(c==s[0])cu++;
                else break;
            }
            dbg(ans);
            ans-=cu/2;
            ans-=cur/2;
            dbg(ans);
            ans*=k;
            dbg(ans);
            ans+=cu/2;
            ans+=cur/2;
            ans+=((cu+cur)/2)*(k-1);
            dbg(ans,cu,cur);
            cout<<ans<<'\n';
        }
    }

    return 0;
}
