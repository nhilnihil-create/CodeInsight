#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 100005
#define ll long long

#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << ": " << x << "  "
#else
#define debug(x) ;
#endif

ll x;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> x;
    ll h;
    h = x / 500;
    h = h * 1000 + (x - h*500) / 5 * 5;
    cout << h << endl;

    return 0;
}