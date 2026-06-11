//
//AtCoder Beginner Contest 165
//D - Floor Function
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define reAll(x) (x).rbegin(),(x).rend()

using ll = long long;
using ld = long double;

const double PI = 3.14159265358979323846;
const int MOD = 1000000007;

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int main()
{
    ll a, b, n;

    cin >> a >> b >> n;

    n = min(n, b-1);
    cout << a*n/b << endl;
    return 0;
}
