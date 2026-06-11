#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); i++)
#define all(n) begin(n), end(n)
struct cww
{
    cww()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
} star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<char> vchar;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts)
{
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }

template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v)
{
    for (auto &e : t)
        fill_v(e, v);
}
int N,M;
vvint graph,g;
struct edge
{
    long long to, cost;
};
using P = pair<int, int>;
int V;
const int MAX_V = 1e5 + 1;


vint dist;

int main()
{
    
    cin>>N>>M;
    int u,v;

    dist.resize(3*MAX_V+1);
    fill_v(dist,INT_MAX/2);
    g.resize(3*MAX_V+1);
    for (size_t i = 0; i < M; i++)
    {
        cin>>u>>v;
        u--;v--;
        for (size_t j = 0; j < 3; j++)
        {
            g[u+j*MAX_V].push_back(v+((j+1)%3)*MAX_V);
        }
        
    }
    int S,T;
    cin>>S>>T;
    S--;T--;
    dist[S]=0;
    queue<int> q;
    q.push(S);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto &&i : g[cur])
        {
            if(dist[cur]+1<dist[i])
            {
                q.push(i);
                dist[i]=dist[cur]+1;
            }
            
        }
        
    }
    if(dist[T]>=INT_MAX/2)
    cout<<-1;
    else
    cout<<dist[T]/3;

    return 0;
}