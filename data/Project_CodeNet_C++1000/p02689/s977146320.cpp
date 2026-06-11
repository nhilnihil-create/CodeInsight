#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define fo(i,n)         for(int i=0;i<n;i++)
#define Fo(i,k,n)       for(int i=k;i<n;i++) 
#define endl            "\n"
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define vec(x)          vector<x>
#define matrix(x)       vector<vector<x>>
#define mem(a,b)        memset(a, b, sizeof a)
#define vii             vector<pair<int,int>>
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define MOD             998244353
#define deb(x)          cerr <<#x<<" = "<<x<<"\n"
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define all(v)          v.begin(),v.end()
#define rep(i,a,b)      for (int i = a; i<b; ++i)
#define len(s)          s.length()
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
int power(int a,int b,int m=mod)
{int ans=1;while(b>0){if(b&1)ans=(ans*a)%m;a=(a*a)%m;b>>=1;}
return ans;}

void angshuGod()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int N = 1e5+1;
const double pi = acos(-1);

vi adj[N];
bool visited[N];
int arr[N];
int cnt = 0;

// void bfs(int node){

// }

void solve(){    

    
    int n,m;
    cin>>n>>m;

    rep(i,1,n+1) cin>>arr[i];

    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for(int i = 1;i<=n;i++){
        if(adj[i].size()==0) cnt++;
        else{
            int currHeight = arr[i];
            bool flag = true;
            for(int x : adj[i]){
                if(arr[x]>=currHeight){
                    flag = false;
                    break;
                }
            }
            if(flag){
                //cout<<"mil gaya "<<i<<"\n";
                cnt++;
            }
        }
    }
    cout<<cnt;
}

 
int32_t main()
{
    angshuGod();

    int t;

    t = 1;
    //cin>>t;

    while(t--){
        solve();
    }
    
    return 0;
}