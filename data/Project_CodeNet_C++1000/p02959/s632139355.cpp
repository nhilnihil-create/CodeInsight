#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace __gnu_pbds;
using namespace std;
/*
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
*/
#define ull unsigned long long int
#define ll long long int
#define ld long double
#define MAX 1000000007
//1e9+7
#define pll pair<ll,ll>
#define pii pair<int,int>
#define piii pair<int,pii>
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FO ifstream fin("a.in");ofstream fout("a.out");
#define TEST int testcase;cin>>testcase;while(testcase--)
#define FTEST int testcase;fin>>testcase;while(testcase--)
#define all(x) (x).begin(),(x).end()
#define mset0(x) memset((x), 0, sizeof((x)));
#define mset1(x) memset((x), -1, sizeof((x)));
#define endl "\n"
#define plll pair<ll,pll>
#define no {cout<<"NO"<<endl;return;}
#define yes {cout<<"YES"<<endl;}
const int maxn=2e5;
typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
/*
vector<int> adj[maxn+1];
bool vis[maxn+1];
ll power(ll a,ull b){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%MAX;
        a=(a*a)%MAX;
        b/=2;
    }
    return(ans);
}
void dfs(int node){
    vis[node]=true;
    for(auto nex:adj[node]){
        if(!vis[nex]) dfs(nex);
    }
}
*/
void solve(){
    int n;
    cin>>n;
    int a[n+1],b[n];
    for(int i=0;i<n+1;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    ll cnt=0;
    int c=0;
    for(int i=0;i<n;i++){
        if(b[i]>a[i]){
            cnt+=a[i];
            c=a[i+1];
            a[i+1]=max(0,a[i+1]-(b[i]-a[i]));
            cnt+=c-a[i+1];
        }
        else if(b[i]<=a[i]){
            cnt+=b[i];
        }
    }
    cout<<cnt;
    return;
}
int main(){
    IO
    solve();



    return(0);
}
