#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    ll x = n;
    if(n >= b-1) x = b-1;
    ll ans = a*(x%b)/b;
    cout << ans << endl;
    return 0;
}
