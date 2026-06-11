#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
#define task "tst"
using namespace std;
const ll N = 3e5 + 9;
const ll inf = 1e9 + 7;
typedef pair<ll,ll> LL;
vector<ll> g[N];
ll n,x,y,d[N],res[N],i;
void BFS(ll scr){
    fill(d,d + n + 1,inf);
    d[scr] = 0;
    queue<ll> q; q.push(scr);
    while(!q.empty()){
        ll t = q.front(); q.pop();
        for (auto i : g[t]){
            if (d[i] > d[t] + 1){
                d[i] = d[t] + 1;
                q.push(i);
            }
        }
    }
    for (ll i = 1;i <= n;i++) res[d[i]]++;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    cin>>n>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
    for (i = 1;i < n;i++){
        g[i].push_back(i + 1);
        g[i + 1].push_back(i);
    }
    for (i = 1;i <= n;i++) BFS(i);
    for (i = 1;i < n;i++) cout<<res[i]/2<<"\n";
}
