#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <queue>
#include <iomanip>
#include <iterator>

#define MOD 1000000007
#define INF 1000000001

using namespace std;
typedef unsigned long long ull;
typedef long long ll;


template <class T>
ostream &operator<<(ostream &o, const vector<T>&obj) {
    o << "["; for (int i = 0; i < (int)obj.size(); ++i) o << (i > 0 ? ", " : "") << obj[i]; o << "]"; return o;
}
template <class T, class U>
ostream &operator<<(ostream &o, const pair<T, U>&obj) {
    o << "(" << obj.first << ", " << obj.second << ")"; return o;
}
template <class T, class U>
ostream &operator<<(ostream &o, const map<T, U>&obj) {
    o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}
template <class T>
ostream &operator<<(ostream &o, const set<T>&obj) {
    o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}
template <class T>
ostream &operator<<(ostream &o, const queue<T>&obj) {
    queue<T> obj_cp = obj;
    bool first = true;
    o << "{";
    while (!obj_cp.empty()) { o << (!first ? ", " : "") << obj_cp.front(); obj_cp.pop(); first = false; }
    o << "}"; return o;
}

void print() {
    cout << "\n";
}
template<class Head, class... Body>
void print(Head head, Body... body) {
    cout << head << " ";
    print(body...);
}

template <class T> struct BIT {
    vector<T> dat[2];
    T UNITY_SUM = 0;
    
    /* [1, n] */
    BIT(int n) { init(n); }
    void init(int n) { for (int iter = 0; iter < 2; ++iter) dat[iter].assign(n + 1, UNITY_SUM); }
    
    /* a, b are 1-indexed, [a, b) */
    inline void sub_add(int p, int a, T x) {
        for (int i = a; i < (int)dat[p].size(); i += i & -i)
            dat[p][i] = dat[p][i] + x;
    }
    inline void add(int a, int b, T x) {
        sub_add(0, a, x * -(a - 1)); sub_add(1, a, x); sub_add(0, b, x * (b - 1)); sub_add(1, b, x * (-1));
    }
    
    /* a is 1-indexed, [a, b) */
    inline T sub_sum(int p, int a) {
        T res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i) res = res + dat[p][i];
        return res;
    }
    inline T sum(int a, int b) {
        return sub_sum(0, b - 1) + sub_sum(1, b - 1) * (b - 1) - sub_sum(0, a - 1) - sub_sum(1, a - 1) * (a - 1);
    }
    
    /* debug */
    void print() {
        for (int i = 1; i < (int)dat[0].size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};


int main(int argc, char const *argv[]) {
    int N;
    ll D, A;
    cin >> N >> D >> A;

    using P = pair<ll, ll>;
    vector<P> M;
    for (int i = 0; i < N; ++i) {
        ll x, h;
        cin >> x >> h;
        M.push_back(P(x, h));
    }
    sort(M.begin(), M.end());
    // print(M);

    vector<int> next_idxs(N);
    int j = 0;
    for (int i = 0; i < N-1; ++i) {
        while (j < N-1 && M[j+1].first - M[i].first <= D*2) {
            j += 1;
        }
        next_idxs[i] = j;
    }
    next_idxs[N-1] = N;
    // print(next_idxs);

    BIT<ll> bit(N);
    for (int i = 0; i < N; ++i) {
        bit.add(i+1, i+2, M[i].second);
    }
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ll cur = bit.sum(i+1, i+2);
        if (cur <= 0) continue;

        ll res = (cur + A - 1) / A;
        int j = next_idxs[i] + 1;
        bit.add(i+1, j+1, -res*A);
        ans += res;
        // print(res);
        // bit.print();
    }

    cout << ans << endl;

    return 0;
}
