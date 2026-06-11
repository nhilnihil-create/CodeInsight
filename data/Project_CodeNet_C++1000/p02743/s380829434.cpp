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
    ll a, b, c;
    cin >> a >> b >> c;
    //cout << 4 * a * b << endl;
    //cout << c * c + a * a + b * b + 2 * (a * b - c * a - b * c) << endl;
    if (4 * a * b < c * c + a * a + b * b + 2 * (a * b - c * a - b * c) && c - a - b > 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
