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
    int N;
    ll D, A;
    cin >> N >> D >> A;
    vector<pair<int,int>> XH(N);
    rep(i,N) cin >> XH[i].first >> XH[i].second;

    sort(XH.begin(), XH.end());

    D *= 2;
    ll total = 0;
    // pair.first:いつまで有効か、pair.secondはダメージはいくらか
    queue<pair<ll,ll>> q;
    ll ans = 0;
    rep(i,N){
        ll x = XH[i].first;
        ll h = XH[i].second;
        while (!q.empty() && q.front().first < x){
            // 範囲外となった爆風を減算
            total -= q.front().second;
            q.pop();
        }
        // 今回のモンスターより前での爆風ダメージを減算
        h -= total;
        if (h > 0){
            // 回数を算出(切り上げ)
            ll num = (h+A-1)/A;
            ans += num;
            ll damage = num * A;
            total += damage;
            q.emplace(x+D, damage);

        }
    }

    cout << ans << endl;

}