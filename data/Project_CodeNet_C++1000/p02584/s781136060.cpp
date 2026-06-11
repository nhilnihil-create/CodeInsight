#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
// #define debug(a) cout << "["; rep(i,a.size()) cout << a[i] << ", "; cout<<"]"<< endl;

const ll mod = 1000000007;

int main() {
    ll x, k, d; cin >> x >> k >> d;
    ll mostCloseX = x % d;
    ll needMove = abs(x % d - x) / d;
    if(needMove >= k) {
        if(x < 0){
            cout << abs(x + d * k) << endl;
        } else {
            cout << abs(x - d * k) << endl;
        }
        return 0;
    }
    ll leftMove = k - needMove;
    if(leftMove % 2 == 0){
        cout << abs(mostCloseX) << endl;
    } else {
        cout << min(abs(mostCloseX + d), abs(mostCloseX - d)) << endl;
    }
    return 0;
}