#include<bits/stdc++.h>

using   namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

#define  all(v)       (v).begin(),(v).end()
#define  rall(v)      (v).rbegin(),(v).rend()
#define  pb           push_back  
#define  eb           emplace_back
#define  mp           make_pair
#define  ff           first
#define  ss           second
#define  pf           push_front
#define  bs           binary_search
#define  lb           lower_bound
#define  ub           upper_bound
#define  umap         unordered_map
#define  uset         unordered_set
#define  dec(x)       fixed<<setprecision(x)
#define  lcm(a,b)    (a*b/__gcd(a,b))

typedef  priority_queue<ll>  pq;
typedef  priority_queue<ll,vector<ll>,greater<ll>> pqmn;
typedef  pair<ll,ll> pll;

const    ll inf=LLONG_MAX;
const    ll mod=1e9+7;
const    ld pi=acos(-1);

vector<ll> arr[1000001];
bool vis[1000001]={false};
void dfs(ll n)
{
    vis[n]=true;
    for(auto i: arr[n]){
        if(!vis[i]){
            dfs(i);
        }
    }
}
                    
void solution()
{ 
    ll n,m;
    cin>>n>>m;
    while(m--){
        ll x,y;
        cin>>x>>y;
        arr[x].pb(y);
        arr[y].pb(x);
    }
    ll cc=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cc++;
            dfs(i);
        }
    }
    cout<<cc-1;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    t=1;
    //cin>>t;
    while(t--){
        solution();
        cout<<"\n";
    }
    return 0;
}
