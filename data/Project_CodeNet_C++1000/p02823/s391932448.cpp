#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
constexpr long long LINF = 1000100010001000100LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() { 
    ll n, a, b; cin >> n >> a >> b;
    if((b-a)%2==0) cout << (b-a)/2 << ln;
    else{
        ll res = LINF * 4;
        //左に寄せる
        ll cnt = min(a-1, b-1), x = a , y = b;
        x -= cnt , y -= cnt;
        x==1?y--:x--; cnt++;
        cnt += abs((y-x)/2);
        chmin(res, cnt);
        //右に寄せる
        cnt = min(n-a, n-b);
            a += cnt, b += cnt;
            a==n?b++:a++; cnt++;
        cnt += (abs(b-a)/2);
        chmin(res, cnt);
        cout << res << ln;
    }
}