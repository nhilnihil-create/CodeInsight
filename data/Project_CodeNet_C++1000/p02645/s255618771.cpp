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
    string S;
    cin >> S;

    // output
    cout << S.substr(0,3) << endl;

    return 0;
}
