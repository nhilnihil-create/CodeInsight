#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 0; i < n; ++i)
#define rep3(i, a, b) for (ll i = a; i < b; ++i)
#define rep4(i, a, b, c) for (ll i = a; i < b; i += c)
#define erep(n) for (ll i = 0; i <= n; ++i)
#define erep2(i, n) for (ll i = 0; i <= n; ++i)
#define erep3(i, a, b) for (ll i = a; i <= b; ++i)
#define erep4(i, a, b, c) for (ll i = a; i <= b; i += c)
#define rrep(i, a, b) for (ll i = a; i > b; --i)
#define rrep2(i, a, b, c) for (ll i = a; i > b; i -= c)
#define errep(i, a, b) for (ll i = a; i >= b; --i)
#define errep2(i, a, b, c) for (ll i = a; i >= b; i -= c)
#define print(a) cout << a << endl;
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
#define cin(x) cin >> x;
const ll MOD = 1000000007;
const double PI = 3.14159265358979323846264338327950;
inline int newline() { putchar('\n'); return 0; }

int factorial(int n) {
    if (n == 1) return 1;
    else return n * factorial(n - 1);
}

int main() {
    int n;
    cin(n);

    vector<pair<int, int>> points(n);
    rep2(i, n) {
        int x, y;
        cin(x); cin(y);
        points[i] = make_pair(x, y);
    }

    vector<int> temp(n);
    rep2(i, n) temp[i] = i;

    int fact = factorial(n);
    double sum = 0;

    do {
        rep3(i, 1, n) {
            int dx = points[temp[i]].first - points[temp[i - 1]].first;
            int dy = points[temp[i]].second - points[temp[i - 1]].second;

            double d = pow(dx * dx + dy * dy, 0.5);
            sum += d;
        }
    } while (next_permutation(temp.begin(), temp.end()));

    printf("%0.12f\n", sum / fact);
    return 0;
}