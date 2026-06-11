#include <bits/stdc++.h>
#include <math.h>
#include <float.h>
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
const int MOD = 1000000007;

int main(){
    ll N,K; cin >> N >> K;
    vector<int> A(N),F(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> F[i];

    sort(A.begin(), A.end());
    sort(F.rbegin(), F.rend());
    
    ll ok = 1e12;
    ll ng = -1;
    
    while(abs(ok-ng)>1){
        ll mid = (ok+ng) / 2;
        auto f = [&](ll mid){
            ll count = 0;

            rep(i,N){
                count += max(0LL, A[i] - mid/F[i]);
            }
        
            return K >= count;
        };
        if(f(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}