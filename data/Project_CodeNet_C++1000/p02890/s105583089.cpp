#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(false), cout << fixed << setprecision(20);
#define int long long
#define gcd __gcd
#define all(x) (x).begin(), (x).end()
const int INF = 1e18, MOD = 1e9 + 7;
template<class T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<class T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}
#define _overload(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(...) _overload(__VA_ARGS__, repi, _rep)(__VA_ARGS__)
#define _rev(i, n) revi(i, n, 0)
#define revi(i, a, b) for(int i = (int)(a - 1); i >= (int)(b); i--)
#define rev(...) _overload(__VA_ARGS__, revi, _rev)(__VA_ARGS__)
#define each(i, n) for(auto&& i: n)
signed main() {
    INCANT;
    int n, a, cnt[333333] = {}, sum[333333] = {};
    cin>>n;
    rep(i, n){
        cin>>a;
        a--;
        sum[cnt[a]]++;
        cnt[a]++;
    }
    int i = n, tmp = n;
    rep(j, 1, n + 1){
        while(tmp < i * j){
            i--;
            tmp -= sum[i];
        }
        cout<<i<<endl;
    }
}
