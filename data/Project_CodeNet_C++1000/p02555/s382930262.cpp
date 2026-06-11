/*!enjoy karo yaar!*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

#include<bits/stdc++.h>
using namespace std;

/*-----<Defines>-----*/
#define     int             long long int
#define     fast()          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     all(x)          begin(x),end(x)
#define     rz(x)           resize(x)
#define     asn(x,y)        assign(x,y)
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     sz(x)           ((int)size(x))
#define     eb              emplace_back
#define     pb              push_back
#define     pf              push_front
#define     pob             pop_back
#define     pof             pop_front
#define     ins             insert
#define     vi              vector<int>
#define     pii             pair<int,int>
#define     mii             map<int,int>
#define     F               first
#define     S               second
#define     remax(a,b)      a=max(a,b)
#define     remin(a,b)      a=min(a,b)
#define     bitcount(x)     __builtin_popcountll(x)
#define     iceil(n,x)      (((n)-1)/(x)+1)
#define     flush           fflush(stdout)

using ull=unsigned long long;
using ll=long long;
using ld=long double;
/*-----</Defines>-----*/

/*-----<Debugging Stuff>-----*/
string to_string(char s)
{   string res="'''";res[1]=s;return res; }

string to_string(string s)
{   return '"'+s+'"'; }

string to_string(const char* s)
{   return to_string((string)s); }

string to_string(bool b)
{   return (b?"true":"false"); }

template<typename A, typename B>
string to_string(pair<A, B> p)
{   return "("+to_string(p.F)+", "+to_string(p.S)+")"; }

template<typename A>
string to_string(A v)
{
    bool first=1; string res="{";
    for(const auto &x:v)
    {
        if(!first)  res+=", ";
        first=0;
        res+=to_string(x);
    }
    res+="}";
    return res;
}

void debug() { cout<<"\n"; }
template<typename Head, typename... Tail>
void debug(Head H, Tail... T)
{
    cout<<" "<<to_string(H);
    debug(T...);
}

#define show(...) cout << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
/*-----</Debugging Stuff>-----*/

/*-----<Mod Operations>-----*/
const int M=1e9+7;
inline int add(int a,int b,int p=M){ a=a+b; if(a>=p) a-=p; return a; }
inline int sub(int a,int b,int p=M){ a=a-b; if(a<0) a+=p; return a; }
inline int mul(int a,int b,int p=M){ a=(a*1ll*b)%p; return a; }
/*-----</Mod Operations>-----*/

/*-----<Constants>-----*/
const ld pi=acos(-1),eps=1e-9;
const ll inf=1e18;
const int N=4e3+5;
/*-----</Constants>-----*/

vector<int> fact(N),invfact(N);

int pw(int x,int n)
{
    int res=1;

    x%=M;
    for(;n;n/=2)
    {
        if(n%2)
            res=(res*x)%M;

        x=(x*x)%M;
    }

    return res;
}

void compute_fact()
{
    fact[0]=1;
    for(int i=1;i<N;++i)
        fact[i]=(fact[i-1]*i)%M;

    invfact[N-1]=pw(fact[N-1],M-2);
    for(int i=N-2;i>=0;--i)
        invfact[i]=(invfact[i+1]*(i+1))%M;
}

int nCr(int n,int r)
{
    if(r<0 || n<r)
        return 0;

    int res=(fact[n]*invfact[r])%M;
    res=(res*invfact[n-r])%M;

    return res;
}

int nPr(int n,int r)
{
    if(r<0 || n<r)
        return 0;

    int res=(fact[n]*invfact[n-r])%M;
    return res;
}


void solve()
{
    compute_fact();

    int sum;
    cin>>sum;

    int ans=0;
    for(int i=1;3*i<=sum;++i)
    {
        int req=sum-3*i;
        int tmp=nCr(req+i-1,i-1);
        ans=add(ans,tmp);
    }

    cout<<ans;
}

int32_t main()
{
    fast();

    int t=1;
    //cin>>t;
    for(int z=1;z<=t;++z)
    {
        solve();
        //cout<<"\n";
    }

    return 0;
}


