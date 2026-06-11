#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;

ll pow(ll a, ll b) {
  if (b == 0) {
    return 1;
  } else if (b % 2 == 0) {
    ll d = pow(a, b / 2);
    return (d * d) % MOD;
  } else {
    ll d = pow(a, b - 1);
    return (a * d) % MOD;
  }
}

ll fact[3000001];
ll invfact[3000001];

int main(){
    ll x,y;
    cin >> x >> y;

    ll a = (2*x-y)/3;
    ll b = (2*y-x)/3;
    if(x != 2*a+b || y != a+2*b){
        cout << 0 << endl;
        return 0;
    }

    fact[0] = 1;
    fact[1] = 1;
    for(ll i = 2; i <= a+b; i++){
        fact[i] = fact[i-1]*i;
        fact[i] %= MOD;
    }
    invfact[a+b] = pow(fact[a+b], MOD-2);
    invfact[0] = 1;
    for(ll i = a+b-1; i > 0; i--){
        if(i ==0) exit(1);
        invfact[i] = invfact[i+1]*(i+1)%MOD;
    }

    ll ans = fact[a+b]*invfact[a] %MOD;
    ans = ans*invfact[b]%MOD; 
    cout << ans%MOD << endl;

    return 0;
}