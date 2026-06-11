#include<bits/stdc++.h>
using namespace std;
#define int long long
const int R = 69966969;
const int MAXN = 2e5 + 69;
int n, k;
int a[MAXN];
int pre[MAXN];
int encode(int i) {
    return ((pre[i] - i) % k + k) % k;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];
    unordered_map<int, int> mp;
    mp.reserve(n + 1);
    mp.max_load_factor(0.25);
    int ans = 0;
    mp[pre[0] ^ R]++;
    for (int i = 1; i <= n; i++) {
        if (i - k >= 0) {
            int tmp = encode(i - k);
            mp[tmp ^ R]--;
        }
        int val = encode(i);
        ans += mp[val ^ R];
        mp[val ^ R]++;
    }
    cout << ans;
}
