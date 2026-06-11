#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
// ----- boost -----
#include <boost/rational.hpp>
#include <boost/multiprecision/cpp_int.hpp>
// ----- using directives and manipulations -----
using boost::rational;
using boost::multiprecision::cpp_int;
using namespace std;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
typedef long long ll;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP(i,num,n) for(int i=num, i##_len=(n); i<i##_len; ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define print(x) (cout << (x) << endl)
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
#define fs first
#define sc second

const int INF = 1e9;
const ll LLINF = 1e16;
const ll MOD = 1e9+7;
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}
 
template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}
 

// 指定した文字cが文字列に何文字入ってるか
ll stringcount(string s, char c) {
    return count(s.cbegin(), s.cend(), c);
}


// 割り算の切り上げ処理
template<typename T>
T rp(T a, T b) {
  return (a + b - 1) / b;
}

// 桁和
template<typename T>
T digsum(T n) {
    T res = 0;
    while(n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}

// 回文判定
bool kai (string s) {
    string t{s};
    reverse(begin(t), end(t));
    return s == t;
}

using pint = pair<int, int>;
using pll = pair<ll, ll>;
 
int64_t N, K, A[200000], F[200000];
 
bool check(int64_t X){
    int64_t need = 0;
    for(int i=0; i<N; i++){
        int64_t ok = X/F[i];
        if(ok < A[i]) need += A[i] - ok;
    }
    return (need <= K);
}
 
int main(){
    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++) cin >> F[i];
    sort(A, A+N);
    sort(F, F+N, greater<>());
    int64_t ok = 1e13, ng = -1;
    while(ok-ng>1){
        int64_t mid = (ok+ng)/2;
        (check(mid) ? ok : ng) = mid;
    }
    cout << ok << endl;
    return 0;
}
