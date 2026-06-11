#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;
const int mod = 1e9 + 7;

int main(){
    ll n;
    cin >> n;
    int u, v;
    ll res = n * (n+1) * (n+2) / 6; // 各頂点を含む[L, R]の数の和
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        if (u > v) swap(u, v);
        res -= u * (n - v + 1); //　各辺を含む[L, R]の数の和
    }
    cout << res << endl;
}