#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<ll> VLL;
typedef vector<vector<ll>> VVLL;
typedef pair<ll, ll> Pair;
template <class T> T input() {T t; cin>>t; return t;}
#define FOR(i,a,b) for (ll i = a; i < b; i++)
#define REP(i,b) FOR(i,0,b)
#define RFOR(i,a,b) for (ll i = a-1; i >= b; i--)
#define RREP(i,a) RFOR(i,a,0)
#define REPALL(i,x) for (ll i = 0; i < x.size(); i++)
#define RREPALL(i,x) for (ll i = x.size()-1; i >= 0; i--)
#define REPITR(itr,x) for (auto itr = (x).begin(); itr != (x).end(); itr++)
#define ALL(x) (x).begin(), (x).end()
#define SORT(x) sort(ALL(x))
#define MIN_ELEMENT(x) min_element(ALL(x))
#define MAX_ELEMENT(x) max_element(ALL(x))
#define COUNT(x,num) count(ALL(x), num)
#define MEMSET(x,val) memset(x, val, sizeof(x))
#define CHMAX(a,b) a = max(a,b)
#define CHMIN(a,b) a = min(a,b)
#define FIND(x,key) (x.find(key) != x.end())
#define IN_RANGE_V2(v,k,x,y) (0<=x+dx[k]&&x+dx[k]<v[y].size()&&0<=y+dy[k]&&y+dy[k]<v.size())
#define debug(x) cerr<<__LINE__<<": "<<(#x)<<" = "<<(x)<<endl;
void YES(bool flag) {cout<<(flag ? "YES" : "NO")<<endl;}
void Yes(bool flag) {cout<<(flag ? "Yes" : "No")<<endl;}
void yes(bool flag) {cout<<(flag ? "yes" : "no")<<endl;}
#define PRINT_ARRAY_H(a) REPALL(__i,a) {cout<<a[__i]<<(__i != a.size()-1 ? " " : "");} newline;
#define PRINT_ARRAY_V(a) REPALL(__i,a) {cout<<a[__i]<<endl;}
#define e1 first
#define e2 second
#define newline putchar('\n')
#define cspace ' '
#define sspace " "
const int INF = 1e7;
const ll MOD = 1e9 + 7;
const double pi = 3.141592653589793;
const VI dx = {1, 0, -1, 0};
const VI dy = {0, 1, 0, -1};
//const VI dx = {1, 1, 0, -1, -1, -1, 0, 1};
//const VI dy = {0, 1, 1, 1, 0, -1, -1, -1};

//蟻本，螺旋本参考
//DisjointSet
//整数配列に対応
class UnionFindTree {
public:
    int size;
    vector<int> rank, p;
    map<int, int> frends;

    UnionFindTree() {}

    UnionFindTree(int num) {
        size = num;
        rank.resize(size, 0);
        p.resize(size, 0);
        for (int i = 0; i < size; ++i) {
            makeSet(i);
        }
    }

    void makeSet(int x)
    {
        p[x] = x;
        rank[x] = 0;
        frends[x] = 1;
    }

    bool same(int x, int y)
    {
        return findSet(x) == findSet(y);
    }

    void unite(int x, int y)
    {
        link(findSet(x), findSet(y));
    }

    void link(int x, int y)
    {
        if (x == y) {
            return;
        } else if (rank[x] > rank[y]) {
            frends[x] += frends[y];
            frends.erase(y);
            p[y] = x;
        } else {
            frends[y] += frends[x];
            frends.erase(x);
            p[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }

    int findSet(int x)
    {
        if (x != p[x]) {
            frends[p[x]] += frends[x];
            frends.erase(x);
            p[x] = findSet(p[x]);
        }
        return p[x];
    }

    int getFrendsNum(int x)
    {
        return frends[findSet(x)];
    }

    int maxUnion()
    {
        int r = 0;
        REPITR(itr,frends) {
            r = CHMAX(r, itr->e2);
        }
        return r;
    }
};

void solve()
{
    int n, m;
    cin>>n>>m;
    UnionFindTree uf(n);
    REP(i,m) {
        int a, b;
        cin>>a>>b;
        a--; b--;
        uf.unite(a,b);
    }
    cout<<uf.maxUnion()<<endl;
}

int main()
{
    cout<<fixed<<setprecision(20);
    int __t = 1;
    //cin>>__t;
    REP(i,__t) {
        solve();
    }
    return 0;
}