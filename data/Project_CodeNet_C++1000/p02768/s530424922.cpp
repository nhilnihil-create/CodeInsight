#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

ll mod = 1000000007;


ll modPow(ll x, ll n){
    if (n == 0) return 1;
    if (n % 2 == 0){
        ll half =  modPow(x, n/2);
        return half * half % mod;
    }else{
        return x * modPow(x, n-1) % mod;
    }
}

ll choose(ll n, ll r){
    ll mul = 1, div = 1;
    for(ll i = 0; i < r; i++){
        mul *= n - i;
        div *= i + 1;
        mul %= mod;
        div %= mod;
    }   
    return mul * modPow(div, mod-2) % mod;
}

int main(){
    ll n, a, b;
    cin >> n >> a >> b;;
    ll ans = modPow(2, n) - choose(n, a) - choose(n, b) - 1;
    ans %= mod;
    if (ans < 0) ans += mod;
    cout << ans << endl;
    return 0;
}