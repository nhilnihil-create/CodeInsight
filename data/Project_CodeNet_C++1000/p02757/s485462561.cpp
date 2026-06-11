#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int
#define ld long double
#define f(t) for(ll i =0;i<t;i++)
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define inf 4e18
#define EPS 1e-3
#define PI 3.1415926535897932385
#define display(v) f(v.size())cout << v[i]<<" "
const double h = 1e-6;
const int MAX_  = 200005;
#define all(v) v.begin(),v.end()

inline ll mul(ll a, ll b){ return (a * 1ll * b) % MOD; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += MOD; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c > MOD) c -= MOD; return c; }
ll sqr(ll x)
{
    return x*x;
}
 //////////////////////*********CODE***********/////////////////////
 //////////////////////////////////////////////////////////////////
struct graph{
    vi v;
};

void bfs(graph G[],int start,vl & d){
    queue<int> q;
    q.push(start);
    d[start] = 0;
   
    while(!q.empty()){
        int from = q.front();
        q.pop();
        for(int i=0;i<G[from].v.size();i++){
            int to = G[from].v[i];
          //  cout << from << "  " << to << "\n";
            if(d[to] == inf){
                d[to] = d[from]+1;
                q.push(to);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,p;    cin>>n>>p;
    string str;    cin>>str;
    ll ans = 0;
    if(p==2 || p==5){
        for(int i =0;i<n;++i){
            if((str[i]-'0')%p == 0){
                ans += (i+1);
            }
        }
        cout << ans;
        return 0;
    }
    ll digit = 0,power = 1;  // upto that index value mod .. from back
    vl mo(p,0);
    for(int i = n-1;i>=0;--i){
        digit = digit + (str[i] - '0')*power;
        digit %= p;
        ans += mo[digit];
        ++mo[digit];
        if(digit==0){
            ++ans;
        }
        power = (power * 10)%p;
    }
    cout << ans ;
   
    return 0;
}
    
