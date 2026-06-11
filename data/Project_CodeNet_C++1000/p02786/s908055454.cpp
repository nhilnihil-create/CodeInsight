#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    ll h; cin >> h;

    ll ans = 0;
    ll cnt = 1;
    while(0 < h){
        h /= 2;
        ans += cnt;
        cnt *= 2;
    }
    cout << ans << endl;

    return 0;
}
