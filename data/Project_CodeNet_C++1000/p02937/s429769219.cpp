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

lint stl(char x){
    return (lint)(x - 'a');
}
int main(){
    STR(s, t); lint n = Size(s);
    vector<vlint> cnt(26, vlint());
    rep(i, 2*n){
        cnt[stl(s[i%n])].pb(i);
    }
    lint ans = -1;
    rep(i, Size(t)){
        auto it = upper_bound(all(cnt[stl(t[i])]), ans%n);
        if (cnt[stl(t[i])].empty()){
            ans = -2; break;
        }
        ans += *it - ans%n;
    }
    print(ans+1);
}
