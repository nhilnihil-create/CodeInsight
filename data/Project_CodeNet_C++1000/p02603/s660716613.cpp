#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (int)(n); i <= i##_len; i++)
#define rrep(i, n) for (int i = (int)(n)-1; 0 <= i; i--)
#define rrep1(i, n) for (int i = (int)(n); 1 <= i; i--)

#define each(it, c) \
    for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define all(obj) (obj).begin(), (obj).end()

#define pcount __builtin_popcount
#define SZ(x) ((int)(x).size())
#define LEN(x) ((int)(x).length())

#define dump(x) cerr << #x << " = " << (x) << endl;

#define endl "\n"

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

typedef long long lint;

using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        if (i == 0) {
            a.push_back(tmp);
            continue;
        }
        if (tmp != a.back()) a.push_back(tmp);
    }
    int sz = SZ(a);
    lint ans = 1000, num = 0;
    rep(i, sz) {
        if (i == 0) {
            if (a[i] < a[i + 1]) {
                num += ans / a[i];
                ans -= a[i] * (ans / a[i]);
            }
        } else if (i == sz - 1) {
            if (a[i - 1] < a[i]) {
                ans += num * a[i];
                num = 0;
            }
        } else if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
            ans += num * a[i];
            num = 0;
        } else if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
            num += ans / a[i];
            ans -= a[i] * (ans / a[i]);
        }
        dump(ans);
        dump(num);
    }
    cout << ans << endl;
}