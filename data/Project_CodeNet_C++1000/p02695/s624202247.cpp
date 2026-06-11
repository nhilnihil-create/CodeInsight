#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef vector<lint> vlint;

#define inf 1e+9
#define endl "\n"
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

#define pb push_back
#define eb emplace_back
#define Size(c) (int)(c).size()

#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))

template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

template <class T, class S> inline bool chmax(T &a, S b) {
    if(a < b) {a = b;return 1;} return 0;
}
template <class T, class S> inline bool chmin(T &a, S b) {
    if(a > b) {a = b;return 1;} return 0;
}
template <class T>
void line(vector<T> &x){for (auto&& xi : x) cin >> xi;}

inline void IN(void){ return;}

template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){ cin >> first; IN(rest...); return;}

#define INT(...) int __VA_ARGS__; IN (__VA_ARGS__)
#define LINT(...) lint __VA_ARGS__; IN (__VA_ARGS__)
#define STR(...) string __VA_ARGS__; IN(__VA_ARGS__)

template <class T> void UNIQUE(vector<T> &x) {
    sort(all(x)); x.erase(unique(all(x)), x.end());
}
template <class T> void print_vec(T first, T end){
    for (auto i = first; i < end - 1; i++) cout << *i << " ";
    cout << *(end-1) << endl;
}
template <class T> void print(T a){ cout << a << endl;};
vector<string> Yes = {"No", "Yes"};


int dfs(vlint tmp, int n, int m, int q, vlint a, vlint b, vlint c, vlint d){
    if (Size(tmp) == n+1){
        int ret = 0;
        rep(i, q){
            if (tmp[b[i]] - tmp[a[i]] == c[i]) ret += d[i];
        }
        return ret;
    }
    int t = tmp.back();
    int ret = 0;
    tmp.pb(t-1);
    rep(i, m - t + 1){
        tmp.back()++;
        chmax(ret, dfs(tmp, n, m, q, a, b, c, d));
    }
    return ret;
}

int main(){
    INT(n, m, q);
    vlint a(q), b(q), c(q), d(q);
    rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];
    int ans = dfs({1}, n, m, q, a, b, c, d);
    print(ans);
}

    

