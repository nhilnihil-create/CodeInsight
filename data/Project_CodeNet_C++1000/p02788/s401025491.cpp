#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
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

// BinaryIndexedTree(Fenwick-Tree); フェニック木
// ：BIT<long long> bit(xx)で初期化、bit.sum(n)で0~n番目までの累積和を計算
template<typename T> class BIT {
private:
    const long long n; vector<T> bit;
public:
    BIT(long long size) : n(size+1), bit(n, 0){}
    BIT(const vector<T>& v) : n((long long)v.size()+1), bit(n, 0){ for(long long i = 0; i < n-1; i++) add(i,v[i]); }
    T sum(long long i){ i++; T s = 0; while(i > 0){ s += bit[i], i -= i & -i; } return s; }
    void add(long long i, T x){ i++; while(i < n) bit[i] += x, i += i & -i; }
    void print(){ for(long long i = 0; i < n-1; i++) cout << sum(i)-sum(i-1) << (i != n-2 ? " " : "\n"); }
    void print_sum(){ for(long long i = 0; i < n; i++) cout << sum(i-1) << (i != n-1 ? " " : "\n"); }
};

int main(){
    Init();
    // n;monster, d;range, a;damage
    ll n, d, a;
    cin >> n >> d >> a;
    vector<pair<ll, ll>> monster(n);
    rep(i, n) cin >> monster[i].first >> monster[i].second;
    sort(all(monster));
    BIT<long long> bit(n+10);

    // 左端のモンスターから処理していく。
    ll ans = 0;
    rep(i, n){
        ll leftHP = monster[i].second - bit.sum(i);
        if(leftHP <= 0) continue;
        // 左端のモンスターの座標+2*dの範囲まで爆弾が届く
        ll pos = monster[i].first;
        ll range = pos + 2*d;
        // 範囲ギリギリのモンスターを求める
        auto it = upper_bound(all(monster), make_pair(range, INFLL));
        ll range_i = it-monster.begin();
        // 爆弾を投げる回数
        ll bomb = (ll)ceil(1.0*leftHP/a);
        ans += bomb;
        bit.add(i, bomb*a);
        bit.add(range_i, -bomb*a);
    }
    cout << ans << endl;
}