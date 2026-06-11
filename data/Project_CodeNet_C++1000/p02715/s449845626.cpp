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
vector<string> YES = {"NO", "YES"};


int mod = 1e9 + 7;
int bit_length(int n){
    for (int i = 31; i >= 0; --i){
        if (n & (1 << i)) return i+1;
    }
    return 1;
}

lint powmod(lint x, lint y, lint m){
    if (y == 0) return 1;
    lint ret = 1;
    rep(i, bit_length(y)+1){
        if (y & (1 << i)){
            ret *= x; ret %= m;
        }
        x *= x; x %= m;
    }
    return ret;
}

int main(){
    INT(n, k);
    vlint cnt(k+1, 0);
    for (int i = k; i > 0; --i){
        cnt[i] += powmod(k/i, n, mod);
        cnt[i] %= mod;
        for (int j = i+i; j <= k; j += i){
            cnt[i] -= cnt[j];
            cnt[i] %= mod;
        }
    }
    lint ans = 0;
    rep1(i, k+1){
        ans += i * cnt[i] % mod;
        ans %= mod;
    }
    if (ans < 0) ans += mod;
    print(ans);
}
    

