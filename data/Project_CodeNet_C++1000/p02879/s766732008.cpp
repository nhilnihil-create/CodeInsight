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
    if (a < 10 && b < 10) {
        cout << a * b << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}
