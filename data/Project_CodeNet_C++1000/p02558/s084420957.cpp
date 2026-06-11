#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vi; 
typedef vector<pll> vpll; 
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
#define endl        '\n'
#define pb          push_back
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define rs(v,n)     v.resize(n)
#define hell        1000000007
//#define hell        998244353
#define peak        9e18
#define pii         acos(-1)
#define clr(a,x)    memset(a,x,sizeof(a))
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

namespace Ops{
template<class y,class z> z expo(ll b,y e,z m){ll a=1;b%=m;while(e!=0){if((e&1)==1){a=a*b;a=a%m;}b=b*b;b%=m;e>>=1;}return a%m;}
template<class y,class z> z power(ll b,y e){ll a=1;while(e!=0){if((e&1)==1){a=a*b;}b=b*b;e>>=1;}return a;}
template<class x,class z> z inv(x b,z m){return expo(b,m-2,m);}
template<class x,class y> x invGeneral(x a,y b){if(a==0)return b==1?0:-1;x m=invGeneral(b%a,a);return m==-1?-1:((1-(ll)b*m)/a+b)%b;}
template<class x,class y> x min(x a,y b){x c;if(a<=b)c=a;else c=b;return c;}
template<class x,class y> x max(x a,y b){x c;if(a>=b)c=a;else c=b;return c;}
}
using namespace Ops;


namespace InOp{
template<class x>istream &operator>>(istream &in,vector<x> &v) {for(auto& i:v)in>>i;return in;}
template<class x,class y> ostream &operator<<(ostream &out,pair<x,y> &p) {out<<"("<<p.F<<","<<p.S<<")";return out;}
template<class x> ostream &operator<<(ostream &out,vector<x> &v) {out<<"Size : "<<v.size()<<endl;for(auto i:v)out<<i<<" ";out<<endl;return out;}
}
using namespace InOp;


namespace Debug{
#ifdef LOCAL
#define deb(...) printall(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void printall(const char* name, Arg1&& arg1){cerr<<name<<" : "<<arg1<<endl;}
template <typename Arg1, typename... Args>
void printall(const char* names,Arg1&& arg1,Args&&... args){const char* comma=strchr(names,',');cerr.write(names,comma-names)<<" : " <<arg1<<" | ";printall(comma+1,args...);}
#else
#define deb(...) void(0)
#endif
}
using namespace Debug;

namespace Bits{
template<class x> constexpr int onbits(x a){return __builtin_popcount(a);}
constexpr int bits(long long x){return 64-__builtin_clzll(x);}//take care of 0
constexpr int bits(int x){return 32-__builtin_clz(x);}//take care of 0
constexpr int traz(int a){return __builtin_ctz(a);}
constexpr int traz(long long a){return __builtin_ctzll(a);}
}
using namespace Bits;

namespace YesNo{
//#define CAPITAL
void yes(){
    #ifdef CAPITAL
    cout<<"YES"<<"\n";
    #else
    cout<<"Yes"<<"\n";
    #endif
}
void no(){
    #ifdef CAPITAL
    cout<<"NO"<<"\n";
    #else
    cout<<"No"<<"\n";
    #endif
}
}
using namespace YesNo;

void maester();
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    cout<<fixed<<setprecision(6);
    ll test=1;
    //cin>>test;
    while(test--)
    {
        maester();
    }
    #ifndef ONLINE_JUDGE
    cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif
    return 0;
}
#define N  200005
vi pa(N);
ll findpa(ll x)
{
    ll y=pa[x];
    if(y==x)return y;
    pa[x]=findpa(y);
    return pa[x];
}
void connect(ll x,ll y)
{
    ll px=findpa(x);
    ll py=findpa(y);
    pa[px]=py;
}
void maester()
{
    ll i,j,k,l,r,m,n,x,y;
    cin>>n>>m;
    for(i=0;i<=n;i++)pa[i]=i;
    while(m--)
    {
        cin>>l>>x>>y;
        if(l)
        {
            if(findpa(x)==findpa(y))cout<<1<<endl;
            else cout<<0<<endl;
        }
        else
        {
            connect(x,y);
        }
    }
}