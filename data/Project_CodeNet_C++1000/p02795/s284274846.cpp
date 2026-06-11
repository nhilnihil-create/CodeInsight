#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define fast_io ios::sync_with_stdio(false)

const int maxn = 1e6 + 7;
const LL INF = 1e12;
const LL mod = 1e9 + 7;

int main() {
    int h,w,n;
    while(cin >> h >> w >> n) {
        cout << (n + max(h,w) - 1) / max(h,w) << endl;
    }
    return 0;
}
