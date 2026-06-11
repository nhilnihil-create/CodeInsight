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

// ±a1 ±a2 ... ±anの最大値を考える問題と読み替える。
// ただし、全ての符号が+または-のいずれか一方のみになる形は不可
// したがって、全てのaiが正であれば最も小さい数をマイナスとして考える。
// 全てのaiが負であれば最も大きい値をプラスと考える。
int main(){
    Init();
    ll n; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));

    ll sum = 0;
    rep(i, n) sum += abs(a[i]);
    // 全て正の場合
    if(a.front() > 0) sum -= 2 * a.front();
    // 全て負の場合
    if(a.back() < 0) sum += 2 * a.back();
    cout << sum << endl;

    ll acc = a.front();
    for(ll i=1; i<n-1; i++){
        if(a[i] >= 0){
            cout << acc << " " << a[i] << endl;
            acc -= a[i];
        }
    }

    cout << a.back() << " " << acc << endl;
    acc = a.back() - acc;

    for(ll i=1; i<n-1; i++){
        if(a[i] < 0){
            cout << acc << " " << a[i] << endl;
            acc -= a[i];
        }
    }
    return 0;
}