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
    ll w, h, x, y;
    cin >> w >> h >> x >> y;
    printf("%.10lf\n", (double)w * (double)h / (double)2);
    if (h % 2 == 0 && h / 2 == y && w % 2 == 0 && w / 2 == x) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}
