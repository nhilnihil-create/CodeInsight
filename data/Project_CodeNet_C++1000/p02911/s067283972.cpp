// 有點不耐煩會破壞偉大的計劃

#include <bits/stdc++.h>

#define append push_back

using namespace std;
using ll = long long;

const int N = 1e5 + 3;
const int M = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long INF = 1e14 + 9;
const int SM = 1e3 + 5;
const int logN = 22, BL = 400;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {1, 0, 0, -1, -1, 1, -1, 1};
const int dy[] = {0, 1, -1, 0, -1, 1, 1, -1};

void debug() {
	cerr << "\n";
}
template<typename Type1, typename... Type2>
void debug(Type1 a, Type2... b) {
    cerr << a << " ";
    debug(b...);
}

long long n, k, q, p[N];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k >> q;

    while(q--) {
        long long x; cin >> x;

        if(x > 1) {
            p[1]--;
            p[x]++;
        }

        if(x < n) {
            p[x + 1]--;
            p[n + 1]++;
        }
    }

    for(long long i = 1; i <= n; i++) {
        p[i] += p[i - 1];

        if(p[i] + k > 0) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
