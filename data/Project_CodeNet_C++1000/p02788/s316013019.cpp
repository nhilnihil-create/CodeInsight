#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e9;

/* BIT: RAQ対応BIT
    初期値は a_1 = a_2 = ... = a_n = 0
    ・add(l,r,x): [l,r) に x を加算する
    ・sum(i): a_1 + a_2 + ... + a_i を計算する
    計算量は全て O(logn)
*/
template <typename T>
struct BIT {
    ll n;             // 要素数
    vector<T> bit[2];  // データの格納先
    BIT(ll n_) { init(n_); }
    void init(ll n_) {
        n = n_ + 1;
        for (ll p = 0; p < 2; p++) bit[p].assign(n, 0);
    }
    void add_sub(ll p, ll i, T x) {
        for (ll idx = i; idx < n; idx += (idx & -idx)) {
            bit[p][idx] += x;
        }
    }
    void add(ll l, ll r, T x) {  // [l,r) に加算
        add_sub(0, l, -x * (l - 1));
        add_sub(0, r, x * (r - 1));
        add_sub(1, l, x);
        add_sub(1, r, -x);
    }
    T sum_sub(ll p, ll i) {
        T s(0);
        for (ll idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[p][idx];
        }
        return s;
    }
    T sum(ll i) { return sum_sub(0, i) + sum_sub(1, i) * i; }
};

//入力
ll n,d,a;
vector<P>x;

//二分探索
// index が条件を満たすかどうか
bool isOK(ll mid,ll id) {
    ll r = x[id].first + 2*d;
    if(x[mid].first<=r)return true;
    else return false;
}
// 汎用的な二分探索のテンプレ
ll binary_search(ll id) {
    ll ok = id; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll ng = n; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid,id)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    cin >> n >> d >> a;
    
    x.resize(n);
    vector<ll>attack(n+1);
    rep(i,n){
        ll a,b;
        cin >> a >> b;
        x[i]={a,b};
    }
    sort(x.begin(),x.end());
    rep(i,n){
        attack[i]=binary_search(i);
    }

    BIT<ll>bit(n);
    rep(i,n){
        bit.add(i+1,i+2,x[i].second);
    }
    ll ans = 0;
    rep(i,n){
        if(bit.sum(i+1)-bit.sum(i)>0){
            ll now = bit.sum(i+1)-bit.sum(i);
            ll c = (now+a-1)/a;
            bit.add(i+1,attack[i]+2,-a*c);
            ans+=c;
        }
    }
    cout << ans << endl;
    return 0;
}
