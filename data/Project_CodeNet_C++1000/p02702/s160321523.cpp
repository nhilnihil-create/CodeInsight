#include <bits/stdc++.h>
// #include <atcoder/all> // NOTE: AtCoderライブラリ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
// using namespace atcoder; // NOTE: AtCoderライブラリ
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef pair<int, int> pii;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int main() {
    string S; cin >> S;
    int N = S.size();

    reverse(S.begin(), S.end());

    const int MOD = 2019;

    map<ll, ll> G;
    G[0] = 1;

    int x = 0;
    int dig = 1;
    rep(i, N) {
        x += (S.at(i) - '0') * dig;
        x %= MOD;
        G[x]++;

        dig *= 10;
        dig %= MOD;
    }

    int cnt = 0;
    for (auto g : G) {
        int x = g.first;
        int y = g.second;

        if (y < 2) continue;
        cnt += (y * (y - 1) / 2);
    }

    cout << cnt << endl;
}
