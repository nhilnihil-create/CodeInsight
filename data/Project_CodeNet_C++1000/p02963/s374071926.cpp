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

int main(){
    Init();
    ll s; cin >> s;
    ll d = 1e9;

    // 1点を(0,0)に固定した場合、s = 1/2 * (x1*y2 - y1*x2)
    // より、s = (x1*y2 - y1*x2)なる(x1,y1), (x2,y2)を探す問題と考えられる
    // ここで更に、x1=1e9, y1=1と固定すると、s = 1e9*y2 - x2となる(x2,y2)を探す問題に帰着する。
    ll x2 = (d-s%d)%d;
    ll y2 = (s+x2)/d;
    cout << "0 0 1000000000 1 " << x2 << " " << y2 << endl;
}