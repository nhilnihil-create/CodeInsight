#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

const int INF = 0x3f3f3f3f;
const ll  LINF = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 2e5+10;
const int mod = 1e9+7;

using namespace std;

int p[maxn],sz[maxn],qtd;

void start(){
    for(int i=0;i<maxn;++i){
        p[i] = i;
        sz[i] = 1;
    }
}

int find_set(int x){
    return p[x] = (p[x] == x ? x : find_set(p[x])); 
}

int same_set(int x,int y){
    return find_set(x) == find_set(y);
}

void union_set(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a==b) return;
    if(sz[a] > sz[b]) swap(a,b);
    p[a] = b;
    sz[b]+=sz[a];
}

void solve(){
    int n,m;
    cin >> n >> m;
    while(m--){
        int x,y;
        cin >> x >> y;
        union_set(x,y);
    }
    for(int i=1;i<=n;++i){
        if(p[i] == i){
            qtd=max(qtd,sz[i]);
        }
    }
    cout << qtd << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    start();

    int t = 1;

    // cin >> t;

    while(t--){
        solve();
    }

    return 0;
}