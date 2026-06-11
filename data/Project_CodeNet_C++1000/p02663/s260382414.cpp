#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::cpp_int;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ll,pair<ll, ll>> lpll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;

#define deg_to_rad(deg) (((deg)/360)*2*PI)

const ll LINF = LLONG_MAX;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;

const ld PI = (acos(-1));
const ld EPS = 0.0000000001;
// cout << fixed << setprecision(10) << middle << endl;

int main() {
    // input, ready
    int H1,M1,H2,M2,K;
    cin >> H1 >> M1 >> H2 >> M2 >> K;

    int getup = 60*H1+M1;
    int sleepdown = 60 *H2 + M2;

    if (sleepdown - getup <= K) cout << 0 << endl;
    else cout << sleepdown - getup - K << endl;

    // output

    return 0;
}
