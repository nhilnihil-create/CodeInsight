#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

typedef pair<int, int> pii;
const int N = int(3e5) + 2;
const int mod = 998244353;

unordered_map<int, int> dem;
int n, x, s[N], cnt[N];

bool Check(int t, int k) {
    if(1ll * t * k > n) return 0;
    if(cnt[t] >= k) return 1;
    return s[t - 1] >= t * (k - cnt[t]);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x;
        ++dem[x];
    }
    for(auto p: dem) ++cnt[p.se];
    for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + cnt[i] * i;
    for(int i = n; i >= 1; --i) cnt[i] += cnt[i + 1];
    for(int i = 1; i <= n; ++i) {
        int mid, low = 0, high = n;
        while(low <= high) {
            mid = (low + high) >> 1;
            if(Check(mid, i)) low = mid + 1;
            else high = mid - 1;
        }
        cout << high << '\n';
    }
}
