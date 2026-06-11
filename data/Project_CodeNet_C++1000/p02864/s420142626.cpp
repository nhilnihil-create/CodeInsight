#include <bits/stdc++.h>
using namespace std;
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
template <size_t I, class H, class... T> struct TupleReaderWriter{static tuple<H,T...> r(istream&i){H v;i>>v;return tuple_cat(tuple<H>(v),TupleReaderWriter<sizeof...(T)-1,T...>::r(i));}static void w(ostream&o,tuple<H,T...>&t,string d){TupleReaderWriter<I-1,H,T...>::w(o,t,d);o<<d<<get<I>(t);}};
template <class H, class... T> struct TupleReaderWriter<0,H,T...>{static tuple<H,T...> r(istream&i){H v;i>>v;return tuple<H>(v);}static void w(ostream&o,tuple<H,T...>&t,string d){o<<get<0>(t);}};
template<class T>istream&operator>>(istream&i,vector<T>&v){for(auto&x:v)i>>x;return i;}
template<class T>ostream&operator<<(ostream&o,vector<T>&v){string delim="";for(auto&x:v)o<<delim<<x,delim=" ";return o;}
template <class... T> istream& operator>>(istream&i,tuple<T...>& t) { t = TupleReaderWriter<sizeof...(T), T...>::r(i); return i; }
template <class... T> ostream& operator<<(ostream& o, tuple<T...>& t) { string delim = " "; TupleReaderWriter<sizeof...(T) - 1, T...>::w(o, t, delim); return o; }
template<typename T> using rev_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using vector2d = vector<vector<T>>;
void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }
// 選ばれた列は無いものとして扱っても問題ない
int main() {
    const i64 INF = 1e16;
    int N, K;
    cin >> N >> K;
    vector<i64> H;
    H.push_back(0);
    for(int i = 0; i < N; i++) {
        i64 h;
        cin >> h;
        H.push_back(h);
    }
    // ダミー要素
    H.push_back(0);
    N += 2;
    // (i, k) -> x
    // k個の列を選んで除いて、一番右にあるものがiである場合の操作回数
    vector2d<i64> dp(N + 1, vector<i64>(K + 1, INF));
    dp[0][0] = 0;
    for(int i = 0; i <= N; i++) {
        for(int k = 0; k <= K; k++) {
            for(int j = 0; j < min(i, k + 1); j++) {
                dp[i][k] = min(dp[i][k],
                    dp[i - j - 1][k - j] + max<i64>(H[i] - H[i - j - 1], 0));
            }
        }
    }
    i64 ans = INF;
    for(int k = 0; k <= K; k++) {
        ans = min(ans, dp[N][k]);
    }
    cout << ans << endl;
    return 0;
}