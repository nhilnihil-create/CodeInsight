#include<bits/stdc++.h>
#define I int
#define S(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define P(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PT(t) printf("Case %d: ",t)
#define PB(a) push_back(a)
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define ll long long 
using namespace std;
#define mx 500004
#define md 1000000007ll
typedef pair<int, int >P;
typedef vector<ll>V;

////////define value/////
template <class T> inline T BM(T p, T e, T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b)
{
    if(b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M)
{
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}
 
 
template <class T>bool ISLEFT(T a, T b, T c)
{
    if(((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1;  //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}

ll fac[mx + 2];
ll hmw(int n, int k){
    if(n > k)return 0;
    return (fac[k] * mdINV(fac[k-n], md))%md;
}
vector<int>v[mx + 2];

ll  bfs(int u, int p, int k){
    ll ch = v[u].size() - (p!=0);
    int k1 = k - 1 - (p != 0);
  //  cout<<u<<" "<<ch<<" "<<k1<<endl;
    ll res = hmw(ch, k1);
  //  cout<<u<<" "<<res<<endl;
    for(int i = 0; i < v[u].size(); i++){
        int x = v[u][i];
        if( x == p)continue;
        res = (res * bfs(x, u, k) ) % md;
    }
    return res % md;
}
int main(){
    fac[0] = 1;
    for(int i = 1; i <= mx; i++){
        fac[i] = (i * fac[i-1]) % md;
    }
    int n,k;
    cin>>n>>k;
    for(int i = 1; i < n; i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout<<(bfs(1, 0, k) * (ll)k) % md<<endl;
    return 0;
}