#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define sortu(x) sort((x).begin(),(x).end())
#define sortd(x) sort((x).begin(),(x).end(), greater<int>())
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
int getInt(){int x;scanf("%d",&x);return x;}
template<typename T>istream& operator>>(istream&i,v(T)&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const v(T)&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const v(T)&a){ll res(0);for(auto&&x:a)res+=x;return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1e9+7;
#define dame0 { puts("0"); return 0;}
#define dame1 { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define yn2 {puts("YES");}else{puts("NO");}
#define yn3 {puts("yes");}else{puts("no");}
#define on {puts("ok");}else{puts("ng");}
#define on2 {puts("OK");}else{puts("NG");}
#define perm(c) sort(all(c));for(bool c##p=1;c##p;c##p=next_permutation(all(c)))
#define outa {cout << ans << endl;}
#define out(x) {cout << x << endl;}
using Graph = vector<vector<int>>;
//mins(ans,now);  ansに最小値が入る
//if(max(ans,now)) ansが小さければ更新して実行
//ll sum = suma(a); 配列aの合計
//int a[33][4];
 
// 深さ優先探索
int c;
vi ans;
Graph G;

void dfs(int v, int p=-1) {
    for (int u : G[v]) {
        if (u == p) continue;  // 親方向へはいけない
        ans[u] += ans[v];
        dfs(u,v);
    }
}

int main() {
    // 頂点数と辺数
    int n, m; cin >> n >> m;

    // グラフ入力受取 (ここでは無向グラフを想定)
    G.resize(n);
    ans.resize(n);
    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);  // 双方向
    }
   rep(i,m){
        int a;
        cin >> a >> c;
        a--;
        ans[a] += c;
    }
    // 頂点 0 をスタートとした探索
    dfs(0);
    rep(i,n) cout << ans[i] << endl;
}
