#include <bits/stdc++.h>
using namespace std;
#define fast                                                                   \
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define ff(i, n) for (int i = 1; i <= n; i++)
#define F first
#define S second
#define pii pair<int,int>
#define sz size()
#define all(v) v.begin(),v.end()
#define pb push_back
#define pf push_front    
#define PB pop_back
#define pll pair<long long, long long>
#define vl vector<int>
#define mp make_pair
#define mod 1000000007
typedef unsigned long long ull;
const int N = 200005;
const int MOD = 998244353 ;

vl g[N];
map<pair<int,int>,int> m;

void dfs(int v, int p){
    int cnt = 1, temp = 0;
    if(p != 0)temp = m[mp(p,v)];
    f(i,g[v].size()){
        int k = g[v][i];
        if(k != p){
            if(cnt == temp)cnt++;
            m[mp(v,k)] = cnt++;
            dfs(k,v);
        }
    }
    return ;
}


void solve(){
    int n, mx = LLONG_MIN;
    cin>>n;
    int a[n+3];
    f(i,n+3)a[i] = 1;
    vector<pair<int,int> > v;
    f(i,n-1){
        int x, y;
        cin>>x>>y;
        v.pb(mp(x,y));
        g[x].pb(y);
        g[y].pb(x);
    }
    ff(i,n)mx = max(mx,(int)g[i].size());
    cout<<mx<<endl;
    dfs(1,0);
    f(i,v.size())cout<<m[v[i]]<<endl;
}


int32_t main() {
    fast
    int t;
    t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
