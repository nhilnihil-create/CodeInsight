#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int main() {
    int N; cin >> N;
    vl A(N); rep(i, N) cin >> A[i];

    map<int, ll> G;
    rep(i, N) G[A[i]]++;

    ll sum = 0;
    map<int, ll> G2;
    for (auto x : G) {
        ll y = x.second * (x.second - 1) / 2;
        G2[x.first] = y;
        sum += y;
    }

    rep(i, N) {
        ll res = sum;
        ll x = G2[A[i]];
        res -= x;

        ll y = G[A[i]];
        y--;
        res += y * (y - 1) / 2;
        
        cout << res << endl;
    }
}
