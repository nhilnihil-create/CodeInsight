#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

ll gcd (ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a%b);
}

int main() {
    ll a, b;
    cin >> a >> b;
    int ans = 1;
    ll gcd_num = gcd(a, b);
    ll tmp = gcd_num;
    for (ll i = 2; i * i <= gcd_num; ++i) {
        if (tmp % i == 0) {
            ++ans;
            while(1) {
                if (tmp % i != 0) break;
                tmp /= i;
            }
        }
    }
    if (tmp != 1) ++ans;
    cout << ans << endl;
    return 0;
}