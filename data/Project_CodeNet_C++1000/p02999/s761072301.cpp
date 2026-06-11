#include <bits/stdc++.h>
using namespace std;

#define rep(i, beg, end) for (int i = (beg); i < (end); i++)
#define rrep(i, beg, end) for (int i = (beg); i >= (end); i--)
typedef long long ll;
typedef pair<ll, ll> P;
typedef unsigned long long ull;
const int INF = 2e9;
const int mod = 1e9 + 7;
const int N = 1010;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

int main(void)
{
    int x, a; cin >> x >> a;
    cout << ((x < a) ? "0" : "10") << endl;
    return 0;
}