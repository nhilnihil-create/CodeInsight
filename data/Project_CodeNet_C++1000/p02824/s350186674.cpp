// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 10;

long long n, m, v, p, a[N], ans;

bool cmp (long long lhs, long long rhs) {
    return rhs < lhs;
}

bool can (long long pos) {
    // pos mitone biad ya na
    if (pos < p)
        return true;
    if (a[pos] + m < a[p - 1])
        return false;
    long long remain = v - (p - 1) - (n - pos);
    if (remain <= 0)
        return true;
    long long saghf = a[pos] + m;
    long long nowcnt = 0;
    long long nowpos = 0;
    for (int i = p - 1; i < pos; i++) {
        long long diff = saghf - a[i];
        if (diff == 0)
            continue;
        if (diff + nowpos >= m)
            nowcnt++;
        nowpos = (diff + nowpos) % m;
    }
    if (nowcnt < remain)
        return false;
    return true;
}

int bin (int b, int e) {
    if (b + 1 == e)
        return e;
    int mid = (b + e) >> 1;
    if (can (mid))
        return bin (mid, e);
    return bin (b, mid);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> v >> p;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort (a, a + n, cmp);
    cout << bin (0, n) << '\n';
	return 0;
}
