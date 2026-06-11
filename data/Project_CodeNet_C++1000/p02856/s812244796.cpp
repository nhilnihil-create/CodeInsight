#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using piii = pair<int, pair<int, int>>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int func(int a) {
    return (a % 10) + (a / 10);
}

pil rec(int d, ll c) {
    if (d == 0)
        return {0, c - 1};
    int tmp = (10 + d - 1) / d;
    if (c < tmp)
        return {d * c, c - 1};
    pil res = rec(func(d * tmp), c / tmp);
    res.second += (c / tmp) * tmp;
    c %= tmp;
    if (c) {
        res.first += d * c;
        res.second += c;
    }
    if (res.first >= 10) {
        res.first = func(res.first);
        res.second++;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int M;
    cin >> M;
    ll cnt = 0;
    int num = 0;
    for (int i = 0; i < M; ++i) {
        int d;
        ll c;
        cin >> d >> c;
        pil tmp = rec(d, c);
        cnt += tmp.second;
        if (i > 0)
            cnt++;
        num += tmp.first;
        if (num >= 10) {
            num = func(num);
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
