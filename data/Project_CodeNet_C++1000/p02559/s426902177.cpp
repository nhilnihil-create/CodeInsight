#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

struct FenwickTree {
    long long bit[N];
    void update (int x, int val) {
        for (int i = x; i < N; i += i & -i) bit[i] += val;
    }

    long long query (int x) {
        long long ans = 0;
        for (int i = x; i > 0; i -= i & -i) ans += bit[i];
        return ans;
    }
} fw;

int n, q, a[N];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i], fw.update(i, a[i]);
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r; l++;
        if (t == 0) fw.update(l, r);
        else cout << fw.query(r) - fw.query(l - 1) << "\n";
    }
    return 0;
}
