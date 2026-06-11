#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
typedef long long ll;
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (ll i = begin; i < (ll)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

ll N, Q;
vector<vector<int>> graph;
vector<ll> num, k;
vector<bool> memo;

void dfs(int n, ll t)
{
    t += num.at(n);
    k.at(n) += t;
    for (auto g : graph.at(n))
    {
        if (memo.at(g))
        {
            continue;
        }
        else
        {
            memo.at(g) = true;
        }
        dfs(g, t);
    }
    return;
}

int main()
{
    cin >> N >> Q;
    graph.resize(N);
    num.resize(N, 0);
    k.resize(N, 0);
    memo.resize(N, false);

    ll a, b;
    rep(1, i, N)
    {
        cin >> a >> b;
        a--;
        b--;
        graph.at(a).push_back(b);
        graph.at(b).push_back(a);
    }

    ll p, x;
    rep(0, i, Q)
    {
        cin >> p >> x;
        p--;
        num.at(p) += x;
    }

    memo.at(0) = true;
    dfs(0, 0);
    rep(0, i, N)
    {
        cout << k.at(i) << ' ';
    }
    cout << endl;
}