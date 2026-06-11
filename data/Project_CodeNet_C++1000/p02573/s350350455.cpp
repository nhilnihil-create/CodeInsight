#define _USE_MATH_DEFINES
#include  <iostream>
#include  <algorithm>
#include  <climits>
#include  <vector>
#include  <string>
#include  <cstring>
#include  <stack>
#include  <queue>
#include  <cmath>
#include  <iomanip>
#include  <set>
#include  <map>
#include  <new>
#include <cstdint>
#include <cctype>
#include  <cstdio>
#include  <sstream>
#include  <bitset>
using namespace std;
#define rep(i,n)  for(int i = 0; i < n; i++)
#define lrep(i,n,m)  for(int i = n; i < m; i++)

using ll = long long;
using ld = long double;
using Vii = vector<vector<int> >;
using Gjudge = vector<vector<bool>>;
using Vi = vector<int>;
using Vl = vector<ll>;
using Vd = vector<double>;
using Vld = vector<long double>;
using Vll = vector<vector<ll> >;
using Vldd = vector<vector<ld> >;
using Vs = vector<string>;
using Vb = vector<bool>;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Pli = pair<ll, int>;
using VPi = vector<Pi>;
using VPl = vector<Pl>;
using VPli = vector<Pli>;
using Ti = tuple<int, int, int>;
using Tl = tuple<ll, ll, ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int Mod = static_cast<int>(1e9 + 7);
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

Vi p; //自分自身を親に
Vi Rank; //0に
Vi setSize; //1に

int find(int x)
{
    if (p[x] == x)  return x;
    else return p[x] = find(p[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;

    int t = setSize[x] + setSize[y];
    setSize[x] = setSize[y] = t;

    if (Rank[x] < Rank[y]) {
        p[x] = y;
    }
    else {
        p[y] = x;
        if (Rank[x] == Rank[y]) Rank[x]++;
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    int n, m;
    cin >> n >> m;
    p.resize(n);
    rep(i, n) p[i] = i;
    Rank.resize(n, 0);
    setSize.resize(n, 1);

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        unite(a, b);
    }
    int ans = 0;
    rep(i, n) {
        ans = max(ans, setSize[i]);
    }
    cout << ans << endl;
}
