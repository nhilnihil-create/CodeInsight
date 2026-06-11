#include <bits/stdc++.h>
#define pii pair<int, int>
#define ss second
#define ff first
#define all(x) ((x).begin(), (x).end())

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const ll oo = 1e14;
const double PI = 3.14159265;

ll exp(ll a, ll b){
    ll ans = 1;

    while (b){
        if (b&1){
            ans = (ans*a)%mod;
        }
        a = (a*a)%mod;
        b >>= 1;
    }
    return ans;
}

ll combina(ll a, ll b){
    ll lim = max(b, a-b), ini = min(b, a-b);
    ll ans = 1;
    for (ll x = a; x>lim; x--) ans = (ans*x)%mod;

    for (ll x = 2; x <=ini; x++) ans = (ans*exp(x, mod-2))%mod;
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    int a = 0 , b =0, x, y;
    cin >> x >> y;

    while (x > 0 || y > 0){
        if ( x >= y){
            x-=2;
            y-=1;
            a++;
        }
        else {
            x-=1;
            y-=2;
            b++;
        }
    }

    if (x != 0 || y != 0){
        cout << "0" << endl;
        return 0;
    }

    cout << combina(a+b, b) << endl;
    return 0;
}