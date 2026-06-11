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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int func(int n){
    while(n>9){
        n /=10;
    }
    return n;
}

int main(){
    int n; cin >> n;
    int cnt[10][10];
    rep(i, 10)rep(j,10) cnt[i][j] = 0;

    for(int i=1; i<=n; i++){
        int f = func(i), e = i%10;
        cnt[f][e]++;
    }
    ll res= 0;
    for(int i=1; i<=n; i++){
        int f = func(i), e = i%10;
        res += cnt[e][f];
    }
    cout << res << ln;
}

