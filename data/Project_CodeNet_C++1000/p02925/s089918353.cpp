#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using vec = vector<ll>;
using vect = vector<double>;
using Graph = vector<vector<ll>>;
#define loop(i, n) for (ll i = 0; i < n; i++)
#define Loop(i, m, n) for (ll i = m; i < n; i++)
#define pool(i, n) for (ll i = n; i >= 0; i--)
#define Pool(i, m, n) for (ll i = n; i >= m; i--)
#define mod 1000000007ll
#define flagcount __builtin_popcount
#define flag(x) (1 << x)
#define flagadd(bit, x) bit |= flag(x)
#define flagpop(bit, x) bit &= ~flag(x)
#define flagon(bit, i) bit &flag(i)
#define flagoff(bit, i) !(bit & (1 << i))
#define all(v) v.begin(), v.end()
#define low2way(v, x) lower_bound(all(v), x)
#define high2way(v, x) upper_bound(all(v), x)
#define idx_lower(v, x) (distance(v.begin(), low2way(v, x)))  //配列vでx未満の要素数を返す
#define idx_upper(v, x) (distance(v.begin(), high2way(v, x))) //配列vでx以下の要素数を返す
#define idx_lower2(v, x) (v.size() - idx_lower(v, x))         //配列vでx以上の要素数を返す
#define idx_upper2(v, x) (v.size() - idx_upper(v, x))         //配列vでxより大きい要素の数を返す
#define putout(a) cout << a << endl
#define Gput(a, b) G[a].push_back(b)
#define Sum(v) accumulate(all(v), 0ll)
#define gcd(x, y) __gcd(x, y)
ll ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return 0;
}
template <typename T>
T lcm(T x, T y)
{
    T z = gcd(x, y);
    return x * y / z;
}
template <typename T>
bool primejudge(T n)
{
    if (n < 2)
        return false;
    else if (n == 2)
        return true;
    else if (n % 2 == 0)
        return false;
    double sqrtn = sqrt(n);
    for (T i = 3; i < sqrtn + 1; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}
//場合によって使い分ける
//const ll dx[4]={1,0,-1,0};
//const ll dy[4]={0,1,0,-1};
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//2次元配列の宣言
//vector<vector<ll>> field(h, vector<ll>(w));
/*
有向グラフまたは無向グラフにサイクルが存在すればtrueを返す
cycle_check1(G):有向グラフにおけるサイクル検出
cycle_check2(G):無向グラフにおけるサイクル検出
*/
struct union_find
{
    vector<long long> par;  //親の番号　
    vector<long long> rank; //木の深さ(根のランクは0)
    vector<long long> siz;  //要素xが根なら木の頂点数を格納する
    //初期化子リストを用いた初期化
    union_find(long long N) : par(N), rank(N), siz(N)
    {
        for (long long i = 0; i < N; i++)
        {
            par[i] = i;
            rank[i] = 0;
            siz[i] = 1;
        }
    }
    //要素xが所属する木の根を再帰的に発見する
    long long root(long long x)
    {
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]); //経路圧縮
    }
    //要素xが属する木と要素yが属する木の併合
    void unite(long long x, long long y)
    {
        long long rx = root(x);
        long long ry = root(y);
        if (rx == ry)
            return; //同じ木に属してたらそのまま
        if (rank[rx] < rank[ry])
        {
            par[rx] = ry; //根がryの木に併合
            siz[ry] = siz[rx] + siz[ry];
        }
        else
        {
            par[ry] = rx; //根がrxの木に併合
            siz[rx] = siz[rx] + siz[ry];
            if (rank[rx] == rank[ry])
                rank[rx]++;
        }
    }
    //要素xが属する木と要素yが属する木が同じならtrueを返す
    bool same(long long x, long long y)
    {
        return root(x) == root(y);
    }
    //要素xが属する木の頂点数を返す
    long long size(long long x)
    {
        return siz[root(x)];
    }
};

bool cycle_check1(const vector<vector<long long>> &G)
{
    vector<long long> ans;
    long long n = (long long)G.size();
    vector<long long> ind(n); // ind[i]: 頂点iに入る辺の数(次数)
    for (long long i = 0; i < n; i++)
    { // 次数を数えておく
        for (long long next : G[i])
        {
            ind[next]++;
        }
    }
    queue<long long> que;
    for (long long i = 0; i < n; i++)
    { // 次数が0の点をキューに入れる
        if (ind[i] == 0)
            que.push(i);
    }
    while (!que.empty())
    { // 幅優先探索
        long long now = que.front();
        ans.push_back(now);
        que.pop();
        for (long long next : G[now])
        {
            ind[next]--;
            if (ind[next] == 0)
            {
                que.push(next);
            }
        }
    }
    return (long long)(ans.size()) != n;
}

bool cycle_check2(const vector<vector<long long>> &G)
{
    long long n = G.size();
    vector<pair<long long, long long>> edges;
    for (long long i = 0; i < n; i++)
    {
        long long siz = G[i].size();
        for (long long j = 0; j < siz; j++)
        {
            if (i < G[i][j])
                edges.push_back(make_pair(i, G[i][j]));
        }
    }
    long long m = edges.size();
    union_find tree(n);
    bool ret = false;
    for (long long i = 0; i < m; i++)
    {
        long long s = edges[i].first, t = edges[i].second;
        if (tree.same(s, t))
        {
            ret = true;
            break;
        }
        tree.unite(s, t);
    }
    return ret;
}
vector<long long> topo_sort(const vector<vector<long long>> &G)
{ // bfs
    vector<long long> ans;
    long long n = (long long)G.size();
    vector<long long> ind(n); // ind[i]: 頂点iに入る辺の数(次数)
    for (long long i = 0; i < n; i++)
    { // 次数を数えておく
        for (long long next : G[i])
        {
            ind[next]++;
        }
    }
    queue<long long> que;
    for (long long i = 0; i < n; i++)
    { // 次数が0の点をキューに入れる
        if (ind[i] == 0)
            que.push(i);
    }
    while (!que.empty())
    { // 幅優先探索
        long long now = que.front();
        ans.push_back(now);
        que.pop();
        for (long long next : G[now])
        {
            ind[next]--;
            if (ind[next] == 0)
            {
                que.push(next);
            }
        }
    }
    return ans;
}
//DAGの最長パスの長さ(最長パスに使われる辺の数)を返す
long long long_path(const vector<vector<long long>> &G)
{
    long long n = G.size();
    vector<long long> topo = topo_sort(G);
    reverse(topo.begin(), topo.end());
    vector<long long> dp(n, 0);
    long long ret = 0;
    //後ろから更新していく
    for (long long i : topo)
    {
        for (long long j : G[i])
        {
            dp[i] = max(dp[i], dp[j] + 1);
        }
        ret = max(ret, dp[i]);
    }
    return ret;
}
int main()
{
    cout << fixed << setprecision(30);
    ll N;
    cin >> N;
    vector<vector<ll>> G(N * (N - 1)); //iとjの試合(0<=i<j<=N-1)は、i*N+j-1とする
    vector<vector<ll>> A(N, vector<ll>(N - 1));
    loop(i, N) loop(j, N - 1)
    {
        cin >> A[i][j];
        A[i][j]--;
    }
    loop(i, N)
    {
        loop(j, N - 2)
        {
            ll F, S;
            ll a1 = i, b1 = A[i][j];
            ll a2 = i, b2 = A[i][j + 1];
            if (a1 > b1)
                swap(a1, b1);
            if (a2 > b2)
                swap(a2, b2);
            F = a1 * N + b1 - 1;
            S = a2 * N + b2 - 1;
            G[F].push_back(S);
        }
    }
    if (cycle_check1(G))
    {
        putout(-1);
        return 0;
    }
    ll ans = long_path(G);
    putout(ans + 1);
    return 0;
}
