#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
struct edge{ll to, cost;};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define INF 1000000000000
#define ALL(a)  (a).begin(),(a).end()
#define large 1000000000000000000
#define mod 1000000007

int modPow(long long a, long long n, long long p) {
  if (n == 0) return 1; // 0乗にも対応する場合
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
  long long t = modPow(a, n / 2, p);
  return (t * t) % p;
}

int main(){
    ll n,a,b;
    cin >> n >> a >> b;
    if(n == 2 && a == 1 && b == 2){
        cout << 0 << endl;
        return 0;
    }
    ll zentai = 2;
    ll ans = 0;
    zentai = modPow(2,n,mod);
    ll x = 1,y=1;
    for(int i = 0; i < a;i++){
        x *= (n-i) % mod;
        x = x % mod;
    }
    for(int i = 1; i <= a;i++){
        y *= i % mod ;
        y = y % mod;
    }
    ll huga = modPow(y,mod-2,mod);
    ll ans1 = x * huga % mod;
    x = 1,y=1;
    for(int i = 0; i < b;i++){
        x *= (n-i) % mod;
        x = x % mod;
    }
    for(int i = 1; i <= b;i++){
        y *= i % mod ;
        y = y % mod;
    }
    ll hoge = modPow(y,mod-2,mod);
    ll ans2 = x * hoge % mod;


    ans = zentai - 1;
    ans += mod - ans1;
    ans %= mod;
    ans += mod - ans2;
    ans %= mod;
    cout << ans << endl;

}