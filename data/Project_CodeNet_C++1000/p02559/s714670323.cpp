#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    fenwick_tree<ll> fw(N);
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        fw.add(i, a);
    }

    for (int i = 0; i < Q; ++i) {
        int com, a, b;
        cin >> com >> a >> b;
        if (com == 0)
            fw.add(a, b);
        else
            cout << fw.sum(a, b) << '\n';
    }

    return 0;
}
