#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<functional>
#define rep(i,n,m) for(int i=(n);i<(int)(m);i++)
#define reps(i,n,m) for(int i=(n);i<=(int)(m);i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define fs first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define LB(a,x) lb(all(a), x) - a.begin()
#define UB(a,x) ub(all(a), x) - a.begin()
#define printfdouble(x) printf("%.20f\n",(x))
#define chartoint(c) (int)((c) - '0')
#define chartoll(c) (long long)((c) - '0')
#define MOD 1000000007
#define itn int
#define enld endl
#define ednl endl
#define icn cin
#define cotu cout
#define Endl endl
#define stirng string
using namespace std;
typedef long long ll;
const double pi = 3.141592653589793;
using Graph = vector<vector<int>>;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b){if(b<a){a=b; return 1;} return 0;}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll value[200100];
ll ans[200100];
int n,q; 
Graph G(200100);

void dfs(int now, int prev, ll val){
    ll newval = val + value[now];
    ans[now] = newval;
    rep(i,0,SZ(G[now])){
        if(G[now][i] == prev) continue;
        dfs(G[now][i], now, newval);
    }
}


int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    cin >> n >> q;
    rep(i,0,n-1){
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    rep(i,0,q){
        int p,x; cin >> p >> x;
        p--;
        value[p] += (ll)x;
    }

    dfs(0, -1, 0LL);

    rep(i,0,n){
        if(i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
