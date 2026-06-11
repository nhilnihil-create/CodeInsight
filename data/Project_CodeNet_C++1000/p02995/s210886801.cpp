#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll tot = b - a + 1;
    tot -= b / c;
    tot += (a - 1) / c;
    tot -= b / d;
    tot += (a - 1) / d;
    ll LCM = c * d / __gcd(c, d);
    tot += b / LCM;
    tot -= (a - 1) / LCM;
    cout << tot << endl;
    return 0;
}