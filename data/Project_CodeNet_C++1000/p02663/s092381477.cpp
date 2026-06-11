//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll h1, m1, h2, m2, k, a, b;

int main(){
    fast_io;

    cin >> h1 >> m1 >> h2 >> m2 >> k;
    a = h1 * 60 + m1;
    b = h2 * 60 + m2;
    a = b - a;
    if(a < 0) a += 60 * 24;
    cout << a - k;

    return 0;
}
