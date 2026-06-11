#include <bits/stdc++.h>
#include <set>
#include <numeric>
#define rep(i,n) for (int i=0; i < (n); ++i)
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;

const ll mx = 1e18;

int main(void) 
{
    int n; cin >> n;
    
    vector<ll> a(n); // vetctor<ll>
    rep(i,n) {
        cin >> a.at(i);
        if (a.at(i) == 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    // 1e18; →　double であるらしい
    ll ans = 1;
    rep(i,n) {

        if (ans*a.at(i) > mx || a.at(i) > mx /ans) { //llに合わせてやる
            cout << -1 << endl;
            return 0;
        }
        ans *= a.at(i);
    }
    // cout << 1e18 << endl;

    
    cout << ans << endl;
    return 0;

}