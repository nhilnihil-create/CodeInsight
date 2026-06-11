#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;


int main(){
    int N; cin >> N;
    vector<ll> A(N+1), B(N);
    rep(i,N+1) cin >> A[i];
    rep(i,N) cin >> B[i];

    ll ans = 0;
    rep(i,N){
        ans += min(A[i], B[i]);
        ll diff = A[i] - B[i];
        if (diff < 0){
            ans += min(abs(diff), A[i+1]);
            A[i+1] = max(0LL, A[i+1]-abs(diff));
        }
    }
    cout << ans << endl;

}

