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
    int n, k;
    ll s;
    cin >> n >> k >> s;
    rep(i, n) {
        if (i != 0) cout << " ";
        if (k == 0) cout << 1000000001 - s;
        else {
            cout << s;
            --k;
        }
    }
    cout << endl;
    return 0;
}
