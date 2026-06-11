#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<string> vs;
const long long INF = 1LL << 58;
const int INT_INF = 1 << 28;
const double PI = acos(-1.0);

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    auto solve = [&](int x, int y, int z) {
        vi a = {x, y, z};
        int i = 0;
        rep(j, N) {
            if (a[i] + '0' == S[j]) i++;
            if (i == 3) return true;
        }
        return false;
    };
    int ans = 0;
    rep(i, 10) {
        rep(j, 10) {
            rep(k, 10) {
                if (solve(i, j, k)) ans++;
            }
        }
    }
    cout << ans << endl;
}