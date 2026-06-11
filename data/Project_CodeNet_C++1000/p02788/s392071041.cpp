#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9+3;
const ll INF = 1e18+3;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    ll N, D, A;
    cin >> N >> D >> A;
    pll p[N];
    rep(i, N) cin >> p[i].first >> p[i].second;
    sort(p, p+N);
    //更新情報
    queue<pll> que;
    ll sum = 0, ans = 0;
    rep(i, N){
        while(!que.empty() && que.front().first+2*D < p[i].first){
            sum -= que.front().second;
            que.pop();
        }
        if(sum >= p[i].second) continue;
        ll n = (p[i].second-sum+A-1)/A;
        ans += n;
        sum += A*n;
        que.push(pll(p[i].first, A*n));
    }
    cout << ans << endl;
}