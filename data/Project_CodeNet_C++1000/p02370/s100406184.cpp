#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
constexpr int di[] = { 0, 1, 0, -1 }, dj[] = { 1, 0, -1, 0 };
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define all(v) (v).begin(), (v).end()
#define MAX 100000
#define vmax 10000
#define sentinel 2000000000
#define INF (1<<29)
constexpr long long int inf = 100000000000000000;
constexpr long long int rinf = -(INT64_MAX);
static const int NIL=-1;

//cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);

vector<int> g[MAX];
list<int> out;
bool V[MAX];
int n;

void dfs(int u){
    V[u]=true;
    for(auto v:g[u]){
        if(!V[v]) dfs(v);
    }
    out.push_front(u);
}

int main(){
    int s,t,m;
    cin>>n>>m;
    rep(i,n) V[i]=false;
    for(int i=0;i<m;i++){
        cin>>s>>t;
        g[s].push_back(t);
    }

    rep(i,n){
        if(!V[i]) dfs(i);
    }

    for(auto it:out){
        cout<<it<<endl;
    }

    return 0;
}




