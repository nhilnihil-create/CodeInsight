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
    ll n; cin >> n;
    ll ans = 0;
    // nが奇数なら答えは常に0
    if(n%2 == 0){
        // n*(n-2)*(n-4)*...*2を素因数分解した時、min(2の個数,5の個数)個が答えとなる。
        // 明らかに2の回数のほうが多いため、5が何回含まれるか考える。
        // 2..nまでに5の冪で割り切れる数がいくつあるかカウントする。
        for(long long i=5; i<=n; i*=5) ans += (n/2)/i;
    } 
    cout << ans << endl;
}