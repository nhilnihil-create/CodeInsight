//x<<y=x*2^y,x>>y=x/2^y
//1e5+3 is prime
//use ll() for using an integer in self-built fn
//(x&-x) bitwise and of (x and its 2's complement) returns (last set bit)
//eg if x=1010 then it will return 0010 
// careful dont print empty container(run time error) 
//v.erase O(n)
//use ("\n") instead of endl as endl flushes the output buffer
//every time so takes more time than \n (TLE)
//stoll() and to_string((less than 1e19))
//INT_MAX is approx 3e10
//For sets use set_name.lower_bound(x)(strictly O(logn)) 
//NOT lb(all(s),x)(O(logn) for random access (eg vector) but for sets it is O(n));
#include<bits/stdc++.h>
typedef long long int ll;
#define ull unsigned long long int
#define lld long double
#define endl "\n"
#define fi first 
#define sec second 
#define sp setprecision 
#define lb lower_bound
#define ub upper_bound
#define For(i, a, b) for(long long int i = (a); i <= (b); i++)
#define Forr(i, a, b) for(long long int i = (a); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define vll vector<ll>
#define vlld vector<lld>
#define vi vector<int>
#define vch vector<char>
#define sll set<ll>
#define sch set<ch>
#define vpll vector< pair<ll,ll> >
#define vpii vector< pair<int,int> >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define mll map<ll, ll>
#define mcll map<char,ll>
#define sz(container) ll((container).size())
#define fill(a,b) memset(a, b, sizeof(a))
#define fast_io ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
lld pi=3.1415926535897932;
const ll MOD=1e9+7;
const ll dx[4]={-1, 0, 1, 0} , dy[4]={0, 1, 0, -1};
const ll dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1} , dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};

/**************************************************
//FENWICK TREE
ll bit[100005];
void update(ll idx, ll val, ll n) 
{ 
    for (; idx <= n; idx += idx&-idx) 
        bit[idx] += val; 
}
ll query(ll idx) 
{ 
    ll sum = 0; 
    for (; idx>0; idx-=idx&-idx) 
        sum += bit[idx]; 
    return sum; 
}
*****************************************************/

ll lcm(ll a, ll b)
{
    ll g=__gcd(a, b);
    return a/g*b;
}

ll binpow(ll a, ll b,ll m) 
{
    a %= m;
    ll res = 1;
    while (b > 0) 
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

/******************************************
ll phi(ll n) 
{
    ll result = n;
    For(i,0,sqrt(n))
    {
        if (n % i == 0) 
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
************************************/

/***************************************
//to check whether a string is whole number(without leading 0s)
bool isNumber(string s) 
{
    if(s=="0") return true;
    if(s[0]=='0') return false;
    For(i,0,sz(s)-1) 
    {
        if (isdigit(s[i]) == false)  return false;
    } 
    return true; 
}
******************************/
/******************************
queue<ll> q;
//p:parent d:depth
vll used(200002),p(200002),d(200002);
vector<vll>adj(200002);
void bfs(ll s)
{
    q.push(s);
    p[s] = -1;
    used[s] = 1;
    while (!q.empty()) 
    {
        ll v = q.front();
        q.pop();
        for (ll u : adj[v]) 
        {
            if (!used[u]) 
            {
                used[u] = 1;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
}
*****************************/
/***********************************

vector<vll >adj(100005);
vll subsz(100005);
void dfs(ll v,ll x) 
{
    subsz[v]=1;
    for(ll u : adj[v]) 
    {
        if (u!=x) dfs(u,v),subsz[v]+=subsz[u];
    }
}  
************************************/
/**********************************
ll used[1005][1005];
char s[1005][1005];
void dfs(ll x,ll y) 
{
    used[x][y]=1;
    For(i,0,3)
    {
       ll nx=x+dx[i],ny=y+dy[i];
       if(used[nx][ny]==0&&s[nx][ny]!='#') dfs(nx,ny);
    }
}
*********/
ll fact[20];
void solve()
{
    fact[0]=1;
    For(j,1,19) fact[j]=j*fact[j-1];
}
int main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast_io;
    ll T=1;//cin>>T;
    For(i,1,T)
    {
        solve();
        ll n;cin>>n;
        vll p(n),q(n);
        For(j,0,n-1) cin>>p[j];
        For(j,0,n-1) cin>>q[j];
        ll ans1=0,ans2=0;ll ch=0;
        For(j,0,n-1)
        {
            ch=0;
            For(k,0,j-1)
            {
                if(p[k]<p[j]) ch++;
            }
            ans1+=(p[j]-1-ch)*fact[n-(j+1)];
        }
        ch=0;
        For(j,0,n-1)
        {
            ch=0;
            For(k,0,j-1)
            {
                if(q[k]<q[j]) ch++;
            }
            ans2+=(q[j]-1-ch)*fact[n-(j+1)];
            //cout<<ans2<<" ";
        }
        cout<<abs(ans1-ans2);
    }
}