#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ff first
#define ss second
#define pb push_back
#define print(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int bexp(int a, int b, int mod)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = (res * a) % mod;

        a = (a * a) % mod; 
        b >>= 1;
    }
    return res;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

const int N = 100010;
const int mod = 998244353;

struct comp {
    bool operator() (const pair<int, int> a, const pair<int, int> b) const
    {
        int d1 = a.ss - a.ff, d2 = b.ss - b.ff;
        return ((d1 > d2) || (d1 == d2 && a.ff < b.ff));
    }
};

int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    int n;
    cin >> n;

    string s;
    while (n--) {
        s += "ACL";
    }

    cout << s << endl;
    return 0;
}