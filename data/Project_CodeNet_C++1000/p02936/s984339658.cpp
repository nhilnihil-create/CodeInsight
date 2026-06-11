#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <tuple>
#include <string>
#include <algorithm>
#include <functional> // greater など
#include <cmath>      // abs など
#include <numeric>    // accumulate, gcd など
#include <cassert>    // assert
#include <stdexcept>
#include <bitset>
using namespace std;

// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
// typedef int128_t ll;
// typedef cpp_int ll;

// GCC, 配列のアクセスなど
#define _GLIBCXX_DEBUG
// Clang, 配列のアクセスなど
#define _LIBCPP_DEBUG 0

// #define NDEBUG 1
// debug用出力 https://trap.jp/post/998/
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << H << " ";
    debug_out(T...);
}
#ifdef NDEBUG
#define debug(...)
#else
#define debug(...) debug_out(__VA_ARGS__)
#endif

//////////////// //////////////// //////////////// //////////////// ////////////////
//////////////// //////////////// //////////////// //////////////// ////////////////

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
const ll N=2e5 + 5;
const ll mod=1e9 + 7;
vector<ll> adj[N];
vector<ll> add(N,0);
vector<bool>visited(N,false);

void dfs(ll src,ll parent,ll val)
{
    visited[src]=true;
    add[src] = add[src] + val;
    for(ll i=0;i<adj[src].size();i++)
    {
        ll v=adj[src][i];
        if(v==parent)
            continue;
        dfs(v,src,add[src]);
    }
}
int main()
{
    fast();
    ll n,q;
    cin>>n>>q;

    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while(q-->0)
    {
        ll v,val;
        cin>>v>>val;
        v--;
        add[v]+=val;
    }


    dfs(0,-1,0);
    for(ll i=0;i<n;i++)
        cout<<add[i]<<" ";
}
