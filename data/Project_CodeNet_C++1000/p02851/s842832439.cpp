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

ll safemod(ll a, ll k){ return (a%k+k)%k; }

int main(){
    Init();
    ll n, k; cin >> n >> k;
    vi a(n+1), sum(n+1);
    // 累積和の計算
    repf(i, n){
        cin >> a[i];
        sum[i] = safemod(a[i]+sum[i-1], k);
    }
    if(k == 1){ cout << 0 << endl; return 0; }
    ll cnt = 0;
    map<ll, ll> occ;
    for(ll j=1; j<=n; j++){
        if(j == 1){
            for(ll i=max(0LL, j-k); i<j; i++) occ[safemod(sum[i]-i, k)]++;
            cnt += occ[safemod(sum[j]-j, k)];
        }
        else{
            if(j-k >= 0) occ[safemod(sum[j-k]-(j-k), k)]--;
            occ[safemod(sum[j-1]-(j-1), k)]++;
            cnt += occ[safemod(sum[j]-j, k)];
        }
    }
    cout << cnt << endl;
}