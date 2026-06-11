#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using vec_b = vector<bool>;
using vec_str = vector<string>;
using graph = mat;
using edge = pair<ll,ll>;
using wgraph = vector<vector<edge>>;

#define INF (1LL << 60)
#define MOD 1000000007

#define REP(i,m,n) for(ll (i)=(m),i##_len=(n);(i)<(i##_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define _PR(x) cout << (x) << endl
#define _PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define pb push_back


void bfs(wgraph G, ll r, vec_b& f, vec& ans)
{
    queue<edge> Q;
    Q.push(make_pair(r,0));
    f[r] = true;
    ll cnt;
    while(!Q.empty()) {
        edge e = Q.front(); Q.pop();
        cnt = 1;
        FORR(ne,G[e.first]) {
            ll nv = ne.first;
            ll k = ne.second;
            if(!f[nv]) {
                if(cnt == e.second) ++cnt;
                ans[k] = cnt;
                Q.push(make_pair(nv,cnt));
                ++cnt;
                f[nv] = true;
            }
        }
    }
}


int main()
{
    ll N;
    cin >> N;
    wgraph G(N);
    ll a, b;
    REP(i,0,N-1) {
        cin >> a >> b;
        --a; --b;
        G[a].pb(make_pair(b,i));
        G[b].pb(make_pair(a,i));
    }

    vec ans(N-1);
    vec_b F(N, false);
    bfs(G, 0, F, ans);
    
    ll K = 0;
    REP(i,0,N-1) K = MAX(K,ans[i]);
    _PR(K);
    REP(i,0,N-1) _PR(ans[i]); 

    return 0;
}

/*



*/