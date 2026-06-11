#include<bits/stdc++.h>
#define Rushia_mywife ios::sync_with_stdio(0);cin.tie(0);
#define rep(i,head,n) for(int i=(head);i<n;i++)
#define int long long
#define F first
#define S second
#define pb push_back
#define p2(n) (1<<(n))
#define lg2(n) __lg(n)
using namespace std;
using pii = pair<long long,long long>;
using ld = long double;
mt19937 mt_rand(time(0));
const int mod = 1000000007;
const int hnum = 998244353;
const ld PI = acos(-1);
const int N = 5010;

int ans,n,k,cnt,len,times;
int p[N];
int c[N];
int mx[N];
bool vis[N];
vector<int>path;


void dfs(int now,int x){
    vis[now] = 1;
    int pre = path.back();
    path.pb(pre+c[p[now]]);
    cnt++;
    mx[cnt] = max(mx[cnt-1],path.back());
    if(!vis[p[now]])
        dfs(p[now],x);
}

void solve(){
    ans = (int)-1e18;
    cin >> n >> k;
    rep(i,1,n+1)
        cin >> p[i];
    rep(i,1,n+1)
        cin >> c[i];
    rep(i,1,n+1){
        memset(vis,0,sizeof(vis));
        mx[0] = (int)-1e18;
        cnt = 0;
        path.clear();
        path.pb(0);
        dfs(i,i);
        len = path.size()-1;
        times = k/len;
        if(times)
            ans = max(ans,path[len]*(times-1)+mx[len]);
        if(path[len]>0)
            ans = max(ans,path[len]*times+max(0LL,mx[k%len]));
        ans = max(ans,mx[min(k,len)]);
    }
    cout << ans << '\n';
}

signed main(){
    Rushia_mywife
    solve();
}