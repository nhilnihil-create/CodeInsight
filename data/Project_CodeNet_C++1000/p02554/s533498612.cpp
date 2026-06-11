#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

ll calc(ll a, ll b, ll p) {
    if (b == 0) {
        return 1;
    } else if (b % 2 == 0) {
        ll d = calc(a, b / 2, p);
        return (d * d) % p;
    } else {
        return (a * calc(a, b - 1, p)) % p;
    }
}


int main(){
    ll N;
    cin >> N;
    static const ll mod = 1000000000 + 7;
    ll ans;

    ans = (calc(10, N, mod) - (calc(9, N, mod) * 2) % mod + calc(8, N, mod)) % mod;
    if(ans < 0){ans += mod;}
    cout << ans << endl;



    return 0;
}
