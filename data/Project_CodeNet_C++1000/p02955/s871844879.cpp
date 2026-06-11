#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define  range(i, l, r) for (int i = (int)(l); i < (int)(r); ++(i))
#define rrange(i, l, r) for (int i = (int)(r) - 1; i >= (int)(l); --(i))

#define  whole(f, x, ...) ([&](decltype((x)) container) { return (f)(  begin(container),  end(container), ## __VA_ARGS__); })(x)
#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__); })(x)

#define endl '\n'
#define debug(x) cerr << "(" << __LINE__ << ")" << #x << ": " << (x) << endl

using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

// constexpr i32 mod   = 998244353;
constexpr i32 mod   = 1e9 + 7;
constexpr i32 inf   = 1001001001;
constexpr i64 infll = 1001001001001001001ll;

constexpr int dx[] = {0, -1, 1, 0, -1, 1, -1, 1}; 
constexpr int dy[] = {-1, 0, 0, 1, -1, -1, 1, 1};

struct IoSetup { IoSetup(int x = 15){ cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(x); cerr << fixed << setprecision(x); } } iosetup;

template <typename T = i64> T input() { T x; cin >> x; return x; }

template <typename T> ostream &operator<<(ostream &os, vector<T> &v) { range(i, 0, v.size()) { os << v[i] << (i + 1 != v.size() ? " " : ""); } return os; } 
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in : v) is >> in; return is; }

template <typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1, T2> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }

template <typename T> vector<T> make_vector(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector(ts...))>(a, make_vector(ts...)); }

template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
// clang-format on

void solver() {
    int N = input(), K = input();
    vector< i64 > A(N);
    cin >> A;
    
    i32 sum = whole(accumulate, A, 0);
    
    vector< i32 > div;
    for (int i = 1; i * i <= sum; ++i) {
        if (sum % i != 0) continue;
        
        if (i * i == sum) div.push_back(i);
        else {
            div.push_back(i);
            div.push_back(sum / i);
        }
    }
    
    rwhole(sort, div);
    for (auto d: div) {
        vector< i32 > md(N);
        range(i, 0, N) {
            md[i] = A[i] % d;
        }
        
        whole(sort, md);
        
        int l = 0, r = N - 1;
        i64 cnt = 0;
        
        while (l < r) {
            int diff = min(md[l], d - md[r]);
            md[l] -= diff;
            md[r] += diff;
            
            cnt += diff;

            if (md[l] == 0) l++;
            if (md[r] == d) r--;
        }
        
        if (cnt <= K) {
            cout << d << endl;
            return;
        }
    }
}

signed main(int argc, char *argv[]) {
    solver();
}
