#include <bits/stdc++.h>
#define LOOP(n) for (int _i = 0; _i < (n); _i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, r, n) for (int i = (r); i < (n); ++i)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int INF = 2100100100;
const int MOD = 1e9 + 7;

// 多次元 vector 生成
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
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

/*  divisor(n)
    入力：整数 n
    出力：nのすべての約数
    計算量：O(√n)
*/
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end(), greater<long long>());
    return ret;
}

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    int sum = 0;
    REP(i, N) {
        cin >> A.at(i);
        sum += A[i];
    }
    auto divi = divisor(sum);

    vector<int> r(N);
    REP(i, divi.size()) {
        // cout << divi[i] << endl;
        REP(j, N) { r[j] = A[j] % divi[i]; }
        sort(ALL(r));
        vector<int> left(N + 1), right(N + 1);
        left[0] = 0;
        right[N] = 0;
        REP(j, N) { left[j + 1] += r[j] + left[j]; }
        for (int j = N - 1; j >= 0; j--) {
            right[j] += (divi[i] - r[j]) + right[j + 1];
        }
        /*
        REP(j, N + 1) { cout << " " << left[j]; }
        cout << endl;
        REP(j, N + 1) { cout << " " << right[j]; }
        cout << endl;
*/
        REP(j, N + 1) {
            if (left[j] == right[j] && left[j] <= K) {
                cout << divi[i] << endl;
                return 0;
            }
        }
    }

    cout << N << endl;
    return 0;
}
