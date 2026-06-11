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
    int N,M,X; cin >> N >> M >> X;
    vector<ll> C(N);
    vector<vector<ll>> A(N, vector<ll>(M));
    rep(i,N){
        cin >> C[i];
        rep(j,M){
            cin >> A[i][j];
        }
    }

    ll ans = INF;
    rep(i,1<<N){
        vector<ll> buy;
        rep(j,N){
            int bit = (i >> j);
            if ((bit & 1) == 1){
                buy.push_back(j);
            }
        }

        vector<ll> understand(M,0);
        ll money = 0;
        for(auto b : buy){
            money += C[b];
            for(int j = 0; j < M; j++){
                understand[j] += A[b][j];
            }
        }
        bool isOK = true;
        rep(j,M){
            if (understand[j] < X) isOK = false;
        }

        if(isOK) ans = min(ans, money);
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;

}