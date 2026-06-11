#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(int)(n); i++)
#define REP1(i,a,b) for(int i=a; i<=(int)(b); i++)
#define ALL(x) begin(x),end(x)
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N=100005;
const int mod=1e9+7;
int n, k;
VI adj[N], A(N,0);

LL mul_mod(LL a, LL b) {
    return (a*b+mod)%mod;
}

void dfs(int u, int p) {
    int nc=k-1;
    if(p!=-1) nc--;
    
    for(auto v:adj[u]) {
        if(v==p) continue;
        A[v]=nc--;
        dfs(v, u);
    }
}

int main() {
    cin >> n >> k;
    REP(i, n-1) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    A[0]=k;
    dfs(0, -1);
    LL ans=1;

    // REP(i, n) cout << A[i] << ' '; cout << endl;
    REP(i,n) ans=mul_mod(ans, A[i]);
    cout << ans << '\n';
    return 0;
}
