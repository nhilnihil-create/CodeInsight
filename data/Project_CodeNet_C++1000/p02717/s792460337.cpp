#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int INF=INT_MAX;
const ld PI=3.1415926535838797323;
const ld E=2.71828183;
const int MOD=1e9+7;
vi bfs(vector<vi>adj,int src){
    //adjacency list, not-weighted, possibly directed ,src is 1-indexed, adj[0].size()=0!!!
    //for n vertices, adj.size()=n+1. (constructed via push_back() ).

    queue<int>q;
    q.push(src);
    vi dst(adj.size(),INF);
    dst[src]=0;
    while(!q.empty()){
        int c=q.front();
        q.pop();
        for(int nbr:adj[c]){
            if(dst[nbr]==INF){
                dst[nbr]=dst[c]+1;
                q.push(nbr);
            }
        }
    }
    return dst;
}
vi bfsParents(vector<vi>adj,int src){
    vi parents=vi(adj.size(),INF);
    parents[src]=-1;
    queue<int>q;
    q.push(src);
    vi dst(adj.size(),INF);
    dst[src]=0;
    while(!q.empty()){
        int c=q.front();
        q.pop();
        for(int nbr:adj[c]){
            if(dst[nbr]==INF){
                parents[nbr]=c;
                dst[nbr]=dst[c]+1;
                q.push(nbr);
            }
        }
    }
    return parents;
}
int powMod(int base,int exp,int mod){
    //base^exp %mod
    int ans=1;
    for(int i=0; i<exp; i++)
        ans=((ans%mod)*(base%mod))%mod;
    return ans;
}
vi divisorsOf(int n){
    //vector of divisors of n (inc. 1 , excl.n)
    vi ans;
    for(int i=1; i*i<=n; i++){
        if(n%i==0)
            ans.push_back(i);
        if(i*i!=n && i!=1)
            ans.push_back(n/i);
    }
    return ans;
}

void solve();

int main() {
    //  int t;
    //cin >> t;
    //while(t--)
    solve();
}
void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << c << " " << a << " "<< b <<"\n";
    
}