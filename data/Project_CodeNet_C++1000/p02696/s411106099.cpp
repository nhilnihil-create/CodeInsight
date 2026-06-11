#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")

typedef long long ll;
typedef long double ld;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define fast() {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);}
#define eb emplace_back
#define pb push_back
#define deb(a) cerr << #a << " = " << a << '\n';

int main()
{
    fast();
    ll a, b, n, x;
    cin >> a >> b >> n;
    x = min(n, b - 1);
    cout << a * x / b - a * (x / b);
    return 0;
}
