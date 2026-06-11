#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
int a[505];

bool test(int x) {
    int           v = 0;
    multiset<int> s;
    for (int i = 1; i <= n; i++) {
        if (a[i] % x)
            s.insert(a[i] % x);
    }
    while (s.size()) {
        // cout << s.size() << endl;
        auto it1 = s.begin();
        auto it2 = s.end();
        --it2;
        int v1 = *it1, v2 = *it2;
        // printf("%d: %d, %d\n", x, v1, v2);
        int d = min(v1, x - v2);
        s.erase(it2);
        s.erase(s.begin());
        v1 -= d, v2 += d;
        v += d;
        if (v1 != 0)
            s.insert(v1);
        if (v2 != x)
            s.insert(v2);
        // printf("%d, %d\n", v1, v2);
    }
    // printf("%d: %d, RT %d\n", x, v, v <= k);
    return v <= k;
}

int main() {
    int sum = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int ans = 1;
    for (int i = 1; i * i <= sum; i++) {
        ll cost = 0;
        if (sum % i == 0) {
            if (test(i))
                ans = max(ans, i);
            if (test(sum / i))
                ans = max(ans, sum / i);
        }
    }
    cout << ans << endl;
}