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
    ll s;
    cin >> s;
    ll a = (s + (ll)1e9 - 1LL) / (ll)1e9;
    ll b = a * (ll)1e9 - s;
    cout << 0 << " " << 0 << " " << 1000000000 << " " << 1 << " " << b << " " << a << endl;
    return 0;
}
