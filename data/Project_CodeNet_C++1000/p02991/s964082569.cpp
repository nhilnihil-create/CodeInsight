#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define mfill(x,y) memset(x,y,sizeof(x))
#define all(v) v.begin(), v.end()
#define in(x,y,h,w) if(0<=x&&x<h&&0<=y&&y<w)
#define y0 y12345
#define y1 y54321

#ifdef LOCAL
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ul = unsigned long;
using ll = long long;
using P = pair<int, int>;
using vint = vector<int>;using vvint = vector<vector<int>>;
using vll = vector<ll>;using vvll = vector<vector<ll>>;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b;return 1;}return 0;}
template <class T>void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}
template <class T>T gcd(T &a, T &b){if(a<b){swap(a,b);} T r = a%b; while(r!=0){a=b;b=r;r=a%b;} return b;}

vint dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
vint dx8 = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8 = {-1, 0, 1, 1, 1, 0, -1, -1};

vint v;
vvll e;

void dfs(ll now, int b){
    if((v[now]&b)>0){
        return;
    }
    v[now] += b;
    rep(i, e[now].size()){
        dfs(e[now][i], (b<4?b*2:1));
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    debug("debug test\n");
    ll n,m;cin>>n>>m;
    e = vector<vll>(n);
    v = vector<int>(n, 0);
    rep(i, m){
        ll vv,u;cin>>u>>vv;
        e[u-1].push_back(vv-1);
    }
    ll s,t;
    cin>>s>>t;
    /*
    dfs(s-1, 1);
    rep(i, n)debug("ddd%d %d\n", i, v[i]);
    if(v[t-1]%2==1){
        cout << 1 << endl;
    }else{
        cout << -1 << endl;
    }*/
    v = vector<int>(n, 0);
    queue<tuple<int, int, int>> q;
    q.push(tuple<int, int, int>(s-1, 1, 0));
    while(!q.empty()){
        tuple<int, int, int> p = q.front();q.pop();
        int now = get<0>(p), b = get<1>(p), cost = get<2>(p);
        if(now == t-1&&b==1){
            cout << cost/3 << endl;
            return 0;
        }
        if((v[now]&b)>0){
            continue;
        }
        v[now] += b;
        rep(i, e[now].size()){
            q.push(tuple<int, int, int>(e[now][i], (b<4?b*2:1), cost+1));
        }
    }
    cout << -1 << endl;
    return 0;
}
