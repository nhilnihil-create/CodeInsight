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
    int x;
    cin >> x;
    if (x >= 400 && x <= 599) {
        cout << 8 << endl;
    }
    else if (x <= 799) {
        cout << 7 << endl;
    }
    else if (x <= 999) {
        cout << 6 << endl;
    }
    else if (x <= 1199) {
        cout << 5 << endl;
    }
    else if (x <= 1399) {
        cout << 4 << endl;
    }
    else if (x <= 1599) {
        cout << 3 << endl;
    }
    else if (x <= 1799) {
        cout << 2 << endl;
    }
    else {
        cout << 1  << endl;
    }
    return 0;
}
