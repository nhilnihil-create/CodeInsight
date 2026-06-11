#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L

bool isPrime(long long x) {
    if (x == 1) return true;
    for (long long i = 2; i*i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

long long gcd(long long a, long long b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

vector<long long> common_divisors(long long a, long long b) {
    long long n = gcd(a, b);
    vector<long long> ans;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i) {
                ans.push_back(i);
            }
            else {
                ans.push_back(n / i);
                ans.push_back(i);
            }
        }
    }
    return ans;
}
vector<int> get_divisors(long long n) {
    vector<int> ans;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i == n / i) {
                ans.push_back(i);
            }
            else {
                ans.push_back(n / i);
                ans.push_back(i);
            }
        }
    }
    sort(ans.rbegin(), ans.rend());
    return ans;
}

bool is_sorted(vector<int> a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] < a[i]) return false;
    }
    return true;
}

const int N = 2000, M = 2000;
int dp[N+1][M+1];

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
            }
            else {
                long long x = 0;
                if (i > 0) {
                    x += dp[i - 1][j]; x %= MOD;
                }
                if (j > 0) {
                    x += dp[i][j - 1]; x %= MOD;
                }
                if (i > 0 && j > 0 && a[i-1] != b[j-1]) {
                    x = (x - dp[i - 1][j - 1]) % MOD;
                }
                dp[i][j] = x;
            }
        }
    }
    int ans = dp[n][m];
    if (ans < 0)
        ans += MOD;
    cout << ans << '\n';
    return 0;
}