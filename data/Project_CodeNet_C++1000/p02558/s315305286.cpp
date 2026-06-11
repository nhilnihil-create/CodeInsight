#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz size()
#define ll long long
#define all(_v) _v.begin(), _v.end()
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pvllvll pair <vector <ll>, vector <ll> >
#define ld long double
#define veci vector <int>
#define vecll vector <ll>


const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const double PI = 3.1415926535897932384626433832795;
const double eps = 1e-9;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;

int p[(int)2e5+10];

int get(int v) {
    return (v == p[v] ? v : p[v] = get(p[v]));
}

void unite(int v, int u) {
    v = get(v), u = get(u);
    if(v == u) return;
    if(rand() & 1) p[v] = u;
    else p[u] = v;
}

void solve() {
    int n, q;
    cin >> n >> q;
    iota(p + 1, p + n + 1, 1);
    while(q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if(!t) unite(u + 1, v + 1);
        else cout << (get(u + 1) == get(v + 1)) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    ///cin >> T;
    while(T--) solve(), cout << '\n';
    return 0;
}
