#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

const int mod = 1000000007;

bool is_odd_digit(int n) {
    int cnt = 0;
    while (n > 0) {
        n /= 10;
        cnt++;
    }
    return cnt % 2 == 1;
}

int main() {
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i++) if (is_odd_digit(i)) ans++;
    cout << ans << endl;
}
