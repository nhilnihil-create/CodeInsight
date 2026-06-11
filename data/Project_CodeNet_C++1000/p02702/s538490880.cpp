#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
#define double long double
const int INF = 1e18, MOD = 2019;

int modpow(int x, int n) {
    return n < 1 ? 1 : modpow(x * x % MOD, n / 2) * (n % 2 ? x : 1) % MOD;
}

int summation(int a) {return a < 1 ? 0 : (a * a + a) / 2;}

signed main() {
    string s;
    int cnt[2222] = {};
    cnt[0]++;
    cin>>s;
    reverse(s.begin(), s.end());
    int now = 0;
    for (int i = 0; i < s.size(); i++) {
        now += modpow(10, i) * (s[i] - '0');
        now %= MOD;
        cnt[now]++;
    }
    int ans = 0;
    for (int i = 0; i < 2020; i++) {
        ans += summation(cnt[i] - 1);
    }
    cout<<ans<<endl;
}