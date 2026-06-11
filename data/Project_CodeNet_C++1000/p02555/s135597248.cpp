/*
    When you are not practicing someone else is,
    and the day u meet them u will Lose.

    So, all you need is Practice, Practice and Practice.
*/
#include <bits/stdc++.h>
using namespace std;
                     
#define int             long long
#define ld              long double
#define mp              make_pair
#define ff              first
#define ss              second
#define pb              push_back
#define fo(i,n)         for(i=0;i<n;i++)
#define fo1(i,n)        for(i=1;i<=n;i++)
#define FO(i,a,b)       for(i=a;i<=b;i++)
#define FOR(i,a,b)      for(i=a;i>=b;i--)
#define all(c)          c.begin(),c.end()
#define rall(c)         c.rbegin(),c.rend()
#define si              set<int>
#define vi              vector<int>
#define mii             map<int,int>
#define pii             pair<int,int>
#define vpii            vector<pii>
#define vvi             vector<vi>
#define usi             unordered_set<int>
#define umii            unordered_map<int,int>
#define pqmx            priority_queue<int>
#define pqmn            priority_queue<int,vi,greater<int> >
#define sp(x)           cout<<setprecision(x)<<fixed;
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)     __builtin_ctzll(x)
#define in(a,n)         vi a(n);fo(i,n)cin>>a[i];
#define in1(a,n)        vi a(n+1);fo1(i,n)cin>>a[i];
#define w(t)            int t;cin>>t;while(t--)
#define sz(v)           (int)v.size()
#define gcd             __gcd
#define lcm(x,y)        x*(y/gcd(x,y))
#define endl            '\n'
#define PI              3.14159265358979323846
const int inf =         1e18;
const int mod =         1e9+7;
void __p(int x) {cout<<x;}
void __p(int32_t x){cout<<x;}
void __p(float x){cout<<x;}
void __p(double x){cout<<x;}
void __p(ld x) {cout<<x;}
void __p(char x){cout <<'\''<<x<<'\'';}
void __p(const char *x){cout <<'\"' <<x<<'\"';}
void __p(const string &x) {cout<<'\"'<<x<<'\"';}
void __p(bool x) {cout<<(x?"true":"false");}
void _p() {cout << "]\n";}
template<typename T,typename V>     void __p(const pair<T,V> &x) {cout<<'{';__p(x.first);cout<<',';__p(x.second);cout<<'}';}
template<typename T>                void __p(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __p(i); cout << "}";}
template <typename T,typename... V> void _p(T t, V... v) {__p(t);if(sizeof...(v))cout<<", ";_p(v...);}
int po(int x,int p) {int ans=1;x%=mod;while(p>0){if(p&1)ans=(ans*x)%mod;p=p>>1;x=(x*x)%mod;}return ans;}
int inv(int x){return po(x,mod-2)%mod;}
#define dbg(x...) cout<<"["<<#x<<"]=[";_p(x)
/**********************************************************************************/



const int N=1e6+6;
int n,m,k,x,y,z,a,b,c,d,i,j,l,r,f,q;



int inv1[N],ifact[N],fact[N];

void NCR()
{
    inv1[1]=1;
    fact[0]=fact[1]=1;
    ifact[0]=ifact[1]=1;
    FO(i,2,N-2)
    {
        inv1[i]=(mod-mod/i)*inv1[mod%i]%mod; 
        fact[i]=i*fact[i-1]%mod;
        ifact[i]=inv1[i]*ifact[i-1]%mod;
    }
}

int ncr(int n,int r)
{
    if(n<r) return 0;
    return (fact[n]*ifact[r]%mod)*ifact[n-r]%mod;
}


void sol()
{   int s;
    cin>>s;
   
    int res=0;
    int i=1;
    while(s-3*i>=0)
    {
        x=s-3*i;
        res=(res+ncr(x+i-1,i-1))%mod;

        i++;
    }


    
    
    
    
    cout<< res <<endl;
}





int32_t main()
{   
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //pre();
    //sp(10);
    NCR();
    // w(t)
    sol();
    return 0;
}
