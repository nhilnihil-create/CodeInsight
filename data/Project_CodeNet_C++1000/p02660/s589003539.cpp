#include <bits/stdc++.h>
#define debug(x) cerr << #x << " " << x << "\n"
#define debug_with_space(x) cerr << #x << " " << x << " "

using namespace std;
typedef long long ll;
typedef pair <ll, ll> pii;
typedef pair <ll, pii> muchie;

const ll NMAX = 61 * 200;
const ll INF = (1LL << 60);
const ll MOD = 1000000007;
const ll BLOCK = 101;

ll calc(ll x){
    ll z = sqrt(x);
    while(z * (z + 1) > x)
        z--;
    return z;
}

int main() {
    ll sum = 0,n,d = 2;
    cin >> n;
    while(d * d <= n){
        ll exp = 0;
        while(n % d == 0){
            n /= d;
            exp++;
        }
        ll rez = calc(exp * 2);
        sum += rez;
        d++;
    }
    if(n > 1){
        sum += calc(2);
    }
    cout << sum;
    return 0;
}
