#include <bits/stdc++.h>

# 1 "<stdin>"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "<stdin>"

using namespace std;

# 1 "../Algo/DP/dp.h" 1
template<class IMPL, class RET>
class DP2 {
public:
    static IMPL* create(int sz1, int sz2, RET emptyValue = -1) {
        auto res = new IMPL();
        res->init(sz1, sz2, emptyValue);
        return res;
    }

    RET calc(int i1, int i2) {
        auto impl = static_cast<IMPL*>(this);
        if (i1 < 0 || i1 >= sz1 || i2 < 0 || i2 >= sz2) {
      return impl->impl(i1, i2);
        }
        auto &res = mem[i1*sz2 + i2];
        if (res == emptyValue) {
            res = impl->impl(i1, i2);
        }
        return res;
    }

private:
    int sz1 = -1;
    int sz2 = -1;
    RET emptyValue;
    vector<RET> mem;

    void init(int sz1, int sz2, RET emptyValue) {
        this->sz1 = sz1;
        this->sz2 = sz2;
        this->emptyValue = emptyValue;
        mem.assign(sz1*sz2, emptyValue);
    }
};
# 5 "<stdin>" 2

const long long INF = 1e18;

struct Input {
    int n, k;
    vector<int> a;
};

struct Output {
    long long ans;
};

struct DP: DP2<DP, long long> {
    Input in;

 long long impl(int i, int j) {
        if (i < 0) {
            return 0;
        }
        long long ans = INF;
        for (int skip = 0; skip <= j; skip++) {
            int prev = i-1-skip;
            int d = max(0, in.a[i] - (prev < 0 ? 0 : in.a[prev]));
            ans = min(ans, calc(prev, j-skip) + d);
            if (prev < 0) {
                break;
            }
        }
  return ans;
 }
};

Output solve(Input in) {
    auto dp = DP::create(in.n, in.k+1);
    dp->in = in;
    long long ans = INF;
    for (int skip = 0; skip <= in.k; skip++) {
        ans = min(ans, dp->calc(in.n-1-skip, in.k-skip));
    }
    delete dp;
    return {ans};
}

Output solveNaive(Input in) {
    long long ans = 1e18;
    for (int mask = 0; mask < (1 << in.n); mask++) {
        vector<int> b;
        int skip = 0;
        for (int i = 0; i < in.n; i++) {
            if ((mask & (1 << i)) > 0) {
                b.push_back(in.a[i]);
            } else {
                skip++;
            }
        }
        if (skip > in.k) {
            continue;
        }
        int prev = 0;
        auto cur = 0ll;
        for (int v: b) {
            cur += max(0, v-prev);
            prev = v;
        }
        ans = min(ans, cur);
    }
    return {ans};
}

Input generateInput() {
    int n = 10;
    int k = rand() % (n+1);
    int mx = 10;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rand() % mx;
    }
    return {n, k, a};
}

void test() {
    while (true) {
        auto in = generateInput();
        auto expected = solveNaive(in);
        auto actual = solve(in);
        if (expected.ans != actual.ans) {
            for (int v: in.a) {
                cout << v << " ";
            }
            cout << endl;
            cout << "expected " << expected.ans << endl;
            cout << "actual " << actual.ans << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto out = solve({n, k, a});
    cout << out.ans << endl;
}
