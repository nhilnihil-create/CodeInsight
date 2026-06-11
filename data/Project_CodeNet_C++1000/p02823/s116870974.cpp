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

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    if (!(abs(a-b)&1)) {
        cout << abs(a-b)/2 << endl;
    }
    else {
        ll d = min({a-1, b-1, n-a, n-b});
        cout << abs(a-b)/2 + 1 + d << endl;
    }
    return 0;
}
