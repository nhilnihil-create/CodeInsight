#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define ll long long int
#define rep(i, n) for(ll (i) = 0; (i) < (n); i++)

int main()
{
    ll n; cin >> n;
    vector<ll> ai(n);
    rep(i, n) cin >> ai[i];
    sort(ai.begin(), ai.end(), greater<ll>());

    ll ans = ai[0];
    if(n % 2){
        ll m = (n-1)/2;
        rep(k, m-1) ans += ai[k+1]*2;
        ans += ai[m];
    }else{
        ll m = n/2;
        rep(k, m-1) ans += ai[k+1]*2;
    }
 
    cout << ans << endl;
    return 0;
}