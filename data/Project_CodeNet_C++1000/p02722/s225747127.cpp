#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define FPEN freopen("in.txt", "r", stdin);
#define TEST(...)                                                              \
    { printf("! "), printf(__VA_ARGS__); }
#else
#define TEST(...)
#define FPEN
#endif
const int maxn = 200009;
typedef long long i64;
typedef pair<i64, i64> pi64;
typedef pair<int, int> pi;
const i64 MOD = 119 << 23 | 1;
class {
  public:
    void solve() {
        i64 n;
        cin >> n;
        set<i64> S;
        i64 N = n - 1;
        for (i64 i = 1; i * i <= N; ++i) {
            if (N % i == 0) {
                if (i >= 2)
                    S.insert(i);
                if (N / i >= 2)
                    S.insert(N / i);
            }
        }
        S.insert(n);
        for (i64 i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                N = n;
                while (N % i == 0) {
                    N /= i;
                }
                N--;
                if (N % i == 0)
                    S.insert(i);
                i64 j = n / i;
                N = n;
                while (N % j == 0)
                    N /= j;
                N--;
                if (N % j == 0)
                    S.insert(j);
            }
        }
        // for (auto i : S)
        //     cout << i << " ";
        // cout << endl;
        cout << S.size() << "\n";
    }
} NSPACE;
int main() {
    FPEN;
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    NSPACE.solve();
}