#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

struct LazySegmentTree {
private:
    int length;
    vector<long long> node, lazy;
public:
    LazySegmentTree(int N) {
        length = 1;
        while (length < N) length *= 2;
        node.resize(2 * length - 1, 0);
        lazy.resize(2 * length - 1, 0);
    }
    void eval(int k, int l, int r) {
        node[k] += lazy[k];
        if (r - l > 1) {
            lazy[2 * k + 1] += lazy[k] / 2;
            lazy[2 * k + 2] += lazy[k] / 2;
        }
        lazy[k] = 0;
    }
    void add(int a, int b, long long x, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = length;
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] += x * (r - l);
            eval(k, l, r);
        } else {
            add(a, b, x, 2 * k + 1, l, (l + r) / 2);
            add(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = node[2 * k + 1] + node[2 * k + 2];
        }
    }
    long long getsum(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = length;
        if (b <= l || r <= a) return 0;
        eval(k, l, r);
        if (a <= l && r <= b) return node[k];
        long long vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
        long long vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
        return vl + vr;
    }
};

int main() {
    int N;
    long long D, A;
    cin >> N >> D >> A;
    vector<pair<long long, long long>> S(N);
    rep(i, N) cin >> S[i].first >> S[i].second;
    S.push_back(pair<long long, long long>{1E15, 0});
    
    sort(S.begin(), S.end());
    LazySegmentTree LST(N);
    rep(i, N) LST.add(i, i + 1, S[i].second);
    long long ans = 0;
    rep(i, N) {
        long long x = LST.getsum(i, i + 1);
        if (x <= 0) continue;
        auto iter = upper_bound(S.begin(), S.end(), pair<long long, long long>{S[i].first + 2 * D, 1E15});
        ans += (x - 1 + A) / A;
        LST.add(i, (int)(iter - S.begin()), -(x - 1 + A) / A * A);
    }
    cout << ans << endl;
}
