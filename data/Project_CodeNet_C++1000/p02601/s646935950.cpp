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
#include <cstring>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int k;
    cin >> k;
    rep(i, k) {
        if (b <= a) {
            b *= 2;
        }
        else if (c <= b) {
            c *= 2;
        }
        else {
            break;
        }
        //cout << a << " " << b << " " << c << endl;
    }
    if (a < b && b < c) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
