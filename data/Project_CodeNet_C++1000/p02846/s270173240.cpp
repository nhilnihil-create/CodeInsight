#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL (1LL<<62) // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    vi t(2), a(2), b(2);
    cin >> t[0] >> t[1];
    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];

    // t[0]、t[1]それぞれで縮まる距離
    ll t0d = (a[0] - b[0]) * t[0];
    ll t1d = (a[1] - b[1]) * t[1];
    // 高橋くんが遅れてる状況で符号を統一
    if(t0d > 0) t0d = -t0d, t1d = -t1d;

    // 初期地点(0m)を除いて、二人の距離が0になった時に出会ったといえる
    // t[0]とt[1]でどのように距離が縮まるか、p+qの値で場合分けする
    
    // 1. 無限回出会うケース（時刻がt[0]+t[1]のたびに二人の距離が0になる）
    if(t0d + t1d == 0) cout << "infinity" << endl;

    // 2. 高橋くんが永遠に離されるケース
    else if(t0d + t1d < 0) cout << "0" << endl;

    // 3. 複数回出会う可能性のあるケース
    else{
        // t[0]+t[1]を1サイクルと呼ぶとすると、k回目のサイクルが終了した時点での位置はk*(p+q)である
        // 次のサイクルに入ることを考えると、
        // 1. k*(t0d+t1d)+t0d < 0 : 正の位置から負に行き、再度+t1dで正に戻ってくるため、0を2回通る
        // 2. k*(t0d+t1d)+t0d = 0 : 正の位置から0に行き、そこから+t1dされるため0を1回通る
        // 3. k*(t0d+t1d)+t0d > 0 : 正の位置から正のまま、そこから+t1dされるため0を1度も通らない
        // と場合分けできる。
        // 1回目のサイクルのみ二人の距離が0mからスタート（出会った状態からスタート）なので+1回
        
        // 上の式を変更し、kは -t0d/(t0d+t1d)の商となり、余りで場合分けする
        ll p = -t0d/(t0d+t1d);
        ll q = -t0d%(t0d+t1d);
        if(q == 0) cout << 2*p -1 +1 << endl;
        else if(q > 0) cout << 2*p +1 << endl;

    }
    return 0;
}