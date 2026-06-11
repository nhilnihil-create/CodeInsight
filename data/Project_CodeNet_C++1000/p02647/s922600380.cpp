
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <iostream>
#include <set>
#include <queue>
#include <vector>

using namespace std;

constexpr static int MAXN = 2e5 + 10;

int n, k;
int a[MAXN];
int cnt[MAXN];

bool step() {
    for (int i = 0; i < n; i++)
        cnt[i] = 0;
    for (int i = 0; i < n; i++) {
        int l = max(0, i - a[i]);
        int r = min(n - 1, i + a[i]) + 1;
        cnt[l]++;
        cnt[r]--;
    }
    bool changed = false;
    int b = 0;
    for (int i = 0; i < n; i++) {
        b += cnt[i];
        changed |= (a[i] != b);
        a[i] = b;
    }
    return changed;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < k; j++) {
        if (!step())
            break;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << (i + 1 == n ? '\n' : ' ');
}
