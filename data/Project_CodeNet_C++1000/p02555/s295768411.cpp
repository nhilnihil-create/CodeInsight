#pragma warning(disable:4996)

#include<iostream>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_map>
#include<fstream>
#include<iomanip>
#include<string>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<stack>
#include<sstream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include <assert.h>
#define pb push_back
#define INF 0x3F3F3F3F //int 下较大值
#define inf 0x3F3F3F3F3F3F3F3F  // ll 下较大值 
#define moD 1000000003
#define pii pair<ll,ll>
#define eps 1e-10
#define equals(a,b) (fabs(a-b)<eps)
#define bug puts("bug")
#define re  register
#define fi first
#define se second
typedef  long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9 + 7;
const ll Mod = 998244352;
const int maxn = 2e6 + 10;
const double Inf = 10000.0;
const double PI = acos(-1.0);
using namespace std;


int bitcount(int x) {
    return x == 0 ? 0 : bitcount(x / 2) + (x & 1);
}


ll mul(ll a, ll b, ll m) {
    ll res = 0;
    while (b) {
        if (b & 1) res = (res + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return res % m;
}

ll quickPower(ll a, ll b, ll m) {
    ll base = a;
    ll ans = 1ll;
    while (b) {
        if (b & 1) ans = mul(ans, base, m);
        base = mul(base, base, m);
        b >>= 1;
    }
    return ans;
}

ll ksm(ll a, ll b, ll m) {
    ll base = a % m;
    ll ans = 1ll;
    while (b) {
        if (b & 1) ans *= base, ans %= m;
        base *= base, base %= m;
        b >>= 1;
    }
    return ans;
}



ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll Lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int readint() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

ll readll() {
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

ull readull() {
    ull x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

void Put(ll x) {
    if (x < 0) putchar('-'), x *= -1;
    if (x > 9) Put(x / 10);
    putchar(x % 10 + '0');
}

ll a[2005];

int main() {
    int s = readint();
    a[0] = 1ll;
    for (int i = 0; i <= s; i++)
        for (int j = 3; j + i <= s; j++)
            a[i + j] = (a[i + j] + a[i]) % MOD;
    Put(a[s]);
}