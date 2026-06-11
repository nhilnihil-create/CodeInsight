#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <set>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using Graph = vector<vector<int> >;
using P = pair<int, int>; 
// MOD
const int MOD = 1000000007;
using ll = long long;
long long INF = 1<<30;
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
//int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }

int H, W;
int field[100][100];

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const double PI=3.14159265358979323846;
bool seen[100][100];

bool memo[110];
bool flag;
Graph G;

int dist[100][100];

bool compare_f(pair<int, int> &x, pair<int, int> &y) {
  return x.second< y.second;
}

struct Unionfind{
    vector<int> par;

    Unionfind(int n) : par(n, -1){}

    int root(int x){
        if(par[x] < 0) return x;
        else return par[x] = root(par[x]);
    } 

    bool issame(int x, int y){
        return root(x) == root(y);
    }

    bool merge(int x, int y){
        x = root(x); y = root(y);
        if(x == y) return false;
        if(par[x]>par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x){
        return -par[root(x)];
    }
};

int main() {
    ll n, d, a; cin >> n >> d >> a;
    vector<P> p(n);
    for(int i=0; i<n; i++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end());
    d = d*2;
    queue<pair<ll,ll> > q;
    ll ans = 0;
    ll tot = 0;
    for(int i=0; i<n; i++){
        ll x = p[i].first;
        ll h = p[i].second;
        while(!q.empty() && q.front().first<x){
            tot -= q.front().second;
            q.pop();
        }
        h -= tot;
        if(h>0){
            ll num = (h + a -1)/a;
            ans += num;
            ll damage = num*a;
            tot += damage;
            q.emplace(x+d, damage);
        }
    }
    cout << ans << endl;
}

