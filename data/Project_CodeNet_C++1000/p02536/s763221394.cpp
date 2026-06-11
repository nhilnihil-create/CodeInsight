#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef list<int> li;

#define all(x) x.begin(),x.end()
#define YES out("YES")
#define NO out("NO")
#define out(x){cout << x << "\n"; return;}
#define FAST     ios_base::sync_with_stdio(false); cin.tie(NULL)
#define print(x){for(auto i:x) cout << i << " "; cout << "\n";}
#define indexed_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

const ll LLINF=1e18;
const int INF=INT_MAX;
const ld PI=acos(-1);//3.1415926535897932384626433
const ld E=2.71828183;
const int MOD=1e9+7;


template <typename T>
struct segment_tree{

    vector<T>tree;
    int size;
    T DEF;
    void init(int n){
        size=1;
        DEF=INF;
        while(size<n)size*=2;
        tree=vector<T>(2*size,0);
    }

    T merge(T a,T b){return a+b;}

    void set(int i,int x,T v,int lx, int rx){
        if(rx-lx==1){
            tree[x]=v;
            return;
        }
        int m=(rx+lx)/2;
        if(i<m){
            set(i,2*x+1,v,lx,m);
        }
        else{
            set(i,2*x+2,v,m,rx);
        }
        tree[x]=merge(tree[2*x+1],tree[2*x+2]);
    }
    void set(int i,T v){
        set(i,0,v,0,size);
    }
    T sum(int l,int r,int x,int lx,int rx){
        if(r<=lx || rx<=l) return 0;//change
        else if(l<=lx && rx<=r)return tree[x];
        int m=(lx+rx)/2;
        return merge(sum(l,r,2*x+1,lx,m),sum(l,r,2*x+2,m,rx));
    }
    T sum(int l,int r){
        return sum(l,r+1,0,0,size);
    }
    void print_tree(){
        for(int i=0; i<tree.size(); i++)
            cout << to_string(tree[i]) << " ";
        cout << "\n";
    }
};
vi bfs(vector<vi>adj, int src){
    queue<int>q;
    vi d(adj.size(),INF);
    q.push(src);
    d[src]=0;
    while(!q.empty()){
        int c=q.front();
        q.pop();
        for(int nbr:adj[c]){
            if(d[nbr]==INF)
                q.push(nbr);
            d[nbr]=min(d[nbr],d[c]+1);
        }
    }
    return d;
}
template<typename T>
void read(vector<T>& v){
    int n=v.size();
    for(int i=0; i<n; i++)
        cin >> v[i];
}
ld log (ld a,ld b){return log(b)/log(a);}
ll power(ll base, ll exp,ll M=LLONG_MAX){//(base^exp)%M
    ll res=1;
    while(exp){
        if(exp%2==1)res=((res%M)*(base%M))%M;
        base=((base%M)*(base%M))%M;
        exp/=2;
    }
    return res;
}
string to_base(int n,int new_base){
    string s;
    int nn=n;
    while(nn){
        s+=to_string(nn%new_base);
        nn/=new_base;
    }
    reverse(all(s));
    return s;
}
ll gcd(ll a,ll b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    ll x= (a/gcd(a,b));
    return b*x;
}
bitset<(const int)(5e5)>sieve(){
    bitset<(const int)(5e5)>ans;
    for(int i=2; i<5e5; i++)
        ans[i]=1;
    for(int i=2; i*i<5e5; i++){
        if(ans[i])
            for(int j=2*i; j<5e5; j+=i)
                ans[j]=0;
    }
    return ans;
}
void solve();

int main() {
    FAST;
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}


vector<vi>adj;
vector<bool>seen;
int ans=0;
void dfs(int src){
    seen[src]=1;
    for(int nbr:adj[src]){
        if(!seen[nbr])
            dfs(nbr);
    }
}
void solve() {
    int n,m;
    cin >> n >> m;
    adj=vector<vi>(n+1);
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    seen=vector<bool>(n+1);
    for(int i=1; i<=n; i++){
        if(!seen[i]){
            ans++;
            dfs(i);
        }
    }
    ans--;
    out(ans)
}