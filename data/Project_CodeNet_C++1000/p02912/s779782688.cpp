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
#define MAX 1000000007
//1e9+7
#define pll pair<ll,ll>
#define pii pair<int,int>
#define piiii pair<pii,pii>
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FO ifstream fin("a.in");ofstream fout("a.out");
#define TEST int testcase;cin>>testcase;while(testcase--)
#define all(x) (x).begin(),(x).end()
#define mset0(x) memset((x), 0, sizeof((x)));
#define mset1(x) memset((x), -1, sizeof((x)));
#define endl "\n"
#define plll pair<ll,pll>
#define logg2 0.30102999566398119521373889472449L
typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const int maxn=2e5;

vector<int> adj[maxn+1];
vector<int> ans;

int state[maxn+1]={0};//  0:not visit    1:processing     -1:processed
bool ok=true;
void dfs(int node){
    if(!ok) return;
    state[node]=1;
    for(auto nex:adj[node]){
        if(state[nex]==0) dfs(nex);
        else if(state[nex]==1) {ok=false;return;}
    }
    state[node]=-1;
    //cout<<node<<" ";
    ans.push_back(node);
}
void solve(){

    int n,m;
    cin>>n>>m;
    int a;
    priority_queue<int> pq;
    while(n--){
        cin>>a;
        pq.push(a);
    }
    while(m--){
        int p=pq.top();
        pq.pop();
        pq.push(p/2);
    }
    ll ans=0;
    while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
    }
    cout<<ans;
    return;
}
int main(){
    IO

    //TEST
    solve();
    return(0);
}
