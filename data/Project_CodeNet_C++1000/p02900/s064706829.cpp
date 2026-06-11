#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x;}

int main()
{
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a,b);
    ll ans = 1;

    for(ll i=2; i*i <= g; i++){
        if(!(g%i)) {
            ans++;
            g /= i;
            while(!(g%i)){
                g /= i;
            }
        }
    }

    if(g != 1) ans++;

    cout << ans << endl;


    return 0;
}