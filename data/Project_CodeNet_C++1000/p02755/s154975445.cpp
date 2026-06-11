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

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= 15000; ++i) {
        if (i * 8 / 100 == a && i * 10 / 100 == b) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
