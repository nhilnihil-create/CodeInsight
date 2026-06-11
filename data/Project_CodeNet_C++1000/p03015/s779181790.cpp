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
    string L;
    cin >> L;
    int N = L.size();
    ll pw2[N+1], pw3[N+1];
    pw2[0] = 1, pw3[0] = 1;
    rep2(i, 1, N){
        pw2[i] = (pw2[i-1]*2)%MOD;
        pw3[i] = (pw3[i-1]*3)%MOD;
    }
    //これまで何回1があったか
    int cnt = 0;
    ll ans = 0;
    rep(i, N){
        if(L[i] == '0') continue;
        ans += (pw2[cnt] * pw3[N-1-i]) % MOD;
        ans %= MOD;
        cnt++;
    }
    ans += pw2[cnt];
    ans %= MOD;
    cout << ans << endl;
}