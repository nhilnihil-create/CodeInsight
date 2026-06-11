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

const ll mod = 1000000007;

int main() {
    ll a,b,c,d;
    cin >> a >> b >>c >> d;
    ll e = c / __gcd(c,d) * d;
    cout <<  b - a + 1 - (b/c - (a-1)/c + b/d - (a-1)/d - (b/e - (a-1)/e)) << endl;
    return 0;
}
