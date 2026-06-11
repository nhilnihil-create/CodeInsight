#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

//aとbの最大公約数
ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

//aとbの最小公倍数
ll lcm(ll a, ll b){
    return a*b/gcd(a,b);
}

//ax+by=cの整数解(x,y)のうちの一つ
pll extgcd(ll a, ll b, ll c){
    if(b == 0){
        return pll(c/a, 0);
    }
    else{
        pll p = extgcd(b, a%b, c);
        ll x = p.second, y = p.first;
        return pll(x, y-(a/b)*x);
    }
}

int main(){
    int N;
    cin >> N;
    ll x[N], y[N];
    rep(i, N) cin >> x[i] >> y[i];
    int ans = inf;
    if(N == 1){
        cout << 1 << endl;
        return 0;
    }
    rep(i, N){
        rep(j, N){
            if(i == j) continue;
            ll a = x[j]-x[i], b = y[j]-y[i];
            int tmp = 0;
            rep(k, N){
                bool same = false;
                rep(l, N){
                    if(x[l]-x[k] == a && y[l]-y[k] == b) same = true;
                }
                if(!same) tmp++;
            }
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
}