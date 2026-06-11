#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define fo(i,j,n) for (int i=(j); i < (n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n, a, b; cin >> n >> a >> b;
    ll res = 0;
    if((b-a)%2){
        ll num = min(min(n-a, n-b), min(a-1, b-1));
        res = num+1 + (b-a-1)/2;
    }else{
        res = (b-a)/2;
    }
    cout << res << ln;
}

    