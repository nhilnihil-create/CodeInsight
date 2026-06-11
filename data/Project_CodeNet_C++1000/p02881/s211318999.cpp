#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    ll n;
    cin >> n;
    ll ans = 1e18;
    for (ll i = 1; i*i <= n; i++) {
        if (n%i != 0) continue;
        ll j = n/i;
        ans = min(ans, i+j-2);
    }
    cout << ans << endl;

    return 0;
}