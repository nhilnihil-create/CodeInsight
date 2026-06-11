#include <bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define repf(i, n) for(int i=1; i<(int)(n+1); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<lli>
#define vvi vector<vector<lli>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
using namespace std;

// 半公倍数の個数を計算
lli hcm(vi &a, lli n, lli m){
    // a1,...,anを全て奇数になるまで割る
    while(a[0]%2 == 0){
        rep(i, n){
            if(a[i]%2 != 0) return 0;
            a[i] /= 2;
        }
        m = floor(m/2.0);
    }
    rep(i, n) if(a[i]%2 == 0) return 0;

    // a1,...,anの最小公倍数の計算
    lli lcm = 1;
    rep(i, n){
        lli gcd = __gcd(lcm, a[i]);
        lcm = (lcm * a[i]) / gcd;
        if(lcm > m) return 0;
    }
    return (m/lcm+1) / 2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    lli n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i], a[i] /= 2;
    cout << hcm(a, n, m) << endl;
}