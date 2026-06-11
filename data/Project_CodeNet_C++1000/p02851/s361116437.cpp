#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> data(n + 1, 0);
    for (int i = 1 ; i <= n ; i++)
        cin >> data[i], data[i]--;
    unordered_map<int, int> cnt;
    int sum1 = 0, sum2 = 0; LL ans = 0;
    for (int i = 0 ; i <= n ; i++) {
        sum1 += data[i];
        sum1 %= k;
        if (i - k >= 0) {
            sum2 += data[i - k];
            sum2 %= k;
            cnt[sum2]--;
        }
        ans += cnt[sum1];
        cnt[sum1]++;
    }
    cout << ans << '\n';
}