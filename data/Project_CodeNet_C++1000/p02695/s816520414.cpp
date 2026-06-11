#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

vector<int> as;
vector<int> bs;
vector<int> cs;
vector<int> ds;

int calc(const vector<int> &acc, const int N, const int Q) {
#ifdef DEBUG
    printf("calc for: ");
    for (auto x : acc) {
        cout << x << " ";
    }
    cout << endl;
#endif

    int ans = 0;
    for (int q = 0; q < Q; q++) {
        int a = as[q], b = bs[q], c = cs[q], d = ds[q];
        if (acc[b] - acc[a] == c) {
            ans += d;
        }
    }
#ifdef DEBUG
    printf("ans: %d\n", ans);
#endif
    return ans;
}

int f(int pos, vector<int> &acc, const int N, const int M, const int Q) {
    if ((int) acc.size() == N) {
        return calc(acc, N, Q);
    }

    if (pos > M) {
        return 0;
    }

    int ans = 0;
    for (int i = pos; i <= M; i++) {
        acc.push_back(i);
        chmax(ans, f(i, acc, N, M, Q));
        acc.pop_back();
    }
    return ans;
}

int solve(const int N, const int M, const int Q) {
    vector<int> acc;
    return f(1, acc, N, M, Q);
}

int main(void) {
    int N, M, Q;
    cin >> N >> M >> Q;

    as.resize(Q);
    bs.resize(Q);
    cs.resize(Q);
    ds.resize(Q);
    for (int i = 0; i < Q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        as[i] = a;
        bs[i] = b;
        cs[i] = c;
        ds[i] = d;
    }

    cout << solve(N, M, Q) << endl;

    return 0;
}
