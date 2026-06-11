#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    ll a, b, k; cin >> a >> b >> k;

    if(a < k) cout << 0 << ' ';
    else{
        cout << a - k << ' ' << b << endl;
        return 0;
    }

    k -= a;
    if(b < k) cout << 0 << endl;
    else cout << b - k << endl;

    return 0;
}
