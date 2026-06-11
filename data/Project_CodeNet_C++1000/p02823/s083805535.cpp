#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD =  1000000007;


int main() {
    ll n, a, b; cin >> n >> a >> b;
    if((a + b) % 2 == 0){
        cout << abs(a - (a + b) / 2) << endl;
        return 0;
    }
    cout << min(a - 1, n - b) + 1 + ((b - a - 1) / 2) << endl;

    return 0;
}
