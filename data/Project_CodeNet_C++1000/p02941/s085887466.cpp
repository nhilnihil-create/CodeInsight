// #define CPP_IO

#pragma region

#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxheap = priority_queue<T>;

#define f first
#define s second

#ifdef LOCAL
#define debug cout
#define debugf(format, ...) printf(format, ##__VA_ARGS__)
#else
#define debug \
    if (0) cout
#define debugf(format, ...) 42
#endif

#define DUMP(a) debug << #a " = " << (a) << "\n";
#define DUMP2(a, b) debug << #a " = " << (a) << " " #b " = " << (b) << "\n";
#define DUMP3(a, b, c) debug << #a " = " << (a) << " " #b " = " << (b) << " " #c " = " << (c) << "\n";
#define DUMP4(a, b, c, d) debug << #a " = " << (a) << " " #b " = " << (b) << " " #c " = " << (c) << " " #d " = " << (d) << "\n";

template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[ ";
    for (auto e : v) os << e << " ";
    return os << "]";
}

template <typename T, typename V>
ostream& operator<<(ostream& os, set<T, V> v) {
    os << "{ ";
    for (auto e : v) os << e << " ";
    return os << "}";
}

template <typename T, typename V, typename S>
ostream& operator<<(ostream& os, map<T, V, S> v) {
    os << "{ ";
    for (auto e : v) os << e << " ";
    return os << "}";
}

template <typename T, typename V>
ostream& operator<<(ostream& os, pair<T, V> x) {
    return os << "( " << x.first << ", " << x.second << " )";
}

template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& e : v) is >> e;
    return is;
}

template <typename T, typename V>
istream& operator>>(istream& is, pair<T, V>& x) {
    return is >> x.first >> x.second;
}

void solve();

int main() {
#ifdef LOCAL
    freopen("data.txt", "r", stdin);
#else
#ifdef CPP_IO
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
#endif
    solve();
}

#pragma endregion

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    cin >> a >> b;
    queue<int> q;
    auto good = [&](int i) {
        i = (i + n) % n;
        return b[i] > a[i] && b[(i + n - 1) % n] + b[(i + 1) % n] <= b[i];
    };
    for (int i = 0; i < n; ++i) {
        if (b[i] < a[i]) {
            cout << "-1\n";
            return;
        }
        if (good(i)) {
            q.push(i);
        }
    }

    ll ans = 0;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        DUMP(i);

        int l = b[(i + n - 1) % n];
        int r = b[(i + 1) % n];

        int s = l + r;

        int targ = a[i];

        if (b[i] < targ) {
            cout << "-1\n";
            return;
        } else if (b[i] == targ || b[i] - s < targ) {
            continue;
        }

        /*
        Find the largest k >= 1 such that

        1. B - (k-1)*s >= s
        2. B - k*s >= targ

        k <= floor(B/s)
        k <= floor((B-targ)/s)

        */

        int k = min(b[i], b[i] - targ) / s;
        DUMP(k);
        ans += 1LL * k;

        b[i] -= k * s;
        if (good(i + 1)) q.push((i + 1) % n);
        if (good(i - 1)) q.push((i + n - 1) % n);
    }
    for (int i = 0; i < n; ++i)
        if (a[i] != b[i]) {
            cout << "-1\n";
            return;
        }
    cout << ans << "\n";
}