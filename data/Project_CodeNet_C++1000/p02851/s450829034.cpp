#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    int N; ll K;
    cin >> N >> K;
    ll A[N];
    rep(i, N){
        cin >> A[i]; A[i]--;
    }
    map<ll, vector<int>> mp;
    ll sum = 0;
    mp[0].pb(0);
    rep(i, N){
        sum += A[i], sum %= K;
        mp[sum].pb(i+1);
    }
    ll ans = 0;
    for(auto &e: mp){
        ll i = 0;
        for(auto &v: e.second){
            i++;
            ll n = lower_bound(all(e.second), v+K) - e.second.begin();
            ans += n-i;
        }
    }
    cout << ans << endl;
}