#include<bits/stdc++.h>
 
using namespace std;
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<long long , long long>
#define pb push_back
#define ll long long
#define ld long double
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define fill(a,b) memset((a),(b),sizeof((a)))
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
ll power(ll x,ll y,ll m){ll r=1;for(;y;y>>=1){if(y&1)r=r*x%m;x=x*x%m;}return r;}
const ll mod = 1e9 + 7;
const ld pi = 3.14159265358979;
 
int visited[200001];

int dfs(int node, int p, vector<int> v[], int  ans){
    visited[node] = 1;
    for(auto to: v[node]){
        if(to == p){
            continue; 
        }
        if(!visited[to]){
            ans  = dfs(to, node, v, ans + 1);
        }
    }
    return ans;
}

int run_test(){
    int n, m;
    cin >> n>> m;
    vector<int> v[n];
    set<pii> s;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(s.count({a, b}) == 0 && s.count({b,a}) == 0){
            s.insert({a, b});
            v[a].pb(b);
            v[b].pb(a);
        }
    }
    fill(visited, 0);
    int ans =1; 
    for(int i=0; i<n; i++){
        if(!visited[i]){
            ans = max(ans, dfs(i, i, v, 1));
        }
    }
    cout << ans;
    return 0;
}
 
int main(){
    FAST;
    ll t;
    t = 1;
 
    while(t--){
        run_test();
    }
}