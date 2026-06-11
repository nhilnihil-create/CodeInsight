#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long power(long long a , long long b) {
    if (!b) return 1;
    long long r = power(a , b / 2);
    r = r * r % MOD;
    if (b&1) return r * a % MOD;
    return r;
}

int add (int a , int b) {
    a += b;
    while (a >= MOD) a -= MOD;
    while (a < 0) a += MOD;
    return a;
}

int mul (int a , int b) {
    return a * 1ll * b % MOD;
}

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#ifdef LOCAL
    freopen("input.in" , "r" , stdin);
#endif
    int n , k;
    cin >> n >> k;

    int ans = 0;

    vector<int> ways(k + 1);
    for (int i = k ;i >= 1 ;i--) {
        ways[i] = power(k / i , n);
        for (int m = i + i ; m <= k ; m += i)
            ways[i] = add(ways[i] , -ways[m]);

        ans = add(ans , mul(ways[i] , i));
    }

    cout << ans;
}
