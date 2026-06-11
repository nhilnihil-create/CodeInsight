#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif

    ll M;
    cin >> M;
    ll sum = 0;
    ll len = 0;
    for (ll i = 0; i < M; i++) {
        ll d, c;
        cin >> d >> c;
        len += c;
        sum += c * d;
    }

    cout << (len - 1) + (sum - 1) / 9 << endl;

    return 0;
}