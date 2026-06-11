// 'That's all it is. A leap of faith'

#include <bits/stdc++.h>

#define append push_back

using namespace std;
using ll = long long;

const int N = 1e5 + 3;
const int M = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 9;
const int SM = 1e3 + 5;
const int logN = 22, BL = 400;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {1, 0, 0, -1, -1, 1, -1, 1};
const int dy[] = {0, 1, -1, 0, -1, 1, 1, -1};

template<typename Type>
long long sz(Type x) {
    return ll(x.size());
}

void debug() {
	cerr << "\n";
}
template<typename Type1, typename... Type2>
void debug(Type1 a, Type2... b) {
    cerr << a << " ";
    debug(b...);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long n; cin >> n;

    vector<vector<long long>> d(n, vector<long long>(2));

    bool flag = false;

    for(long long i = 0; i < n; i++) {
        cin >> d[i][0] >> d[i][1];
        if(i > 1) {
            if(d[i - 2][0] == d[i - 2][1] && d[i - 1][0] == d[i - 1][1] && d[i][0] == d[i][1]) {
                flag = true;
            }
        }
    }

    cout << (flag ? "Yes" : "No");

    return 0;
}
