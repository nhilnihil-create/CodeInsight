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
    int n;
    cin >> n;
    int ans = 0;
    int num[10][10] = {0};
    for (int i = 1; i <= n; ++i) {
        int bottom = i % 10;
        int tmp = i;
        int top = 0;
        while(1) {
            if (tmp / 10 == 0) {
                top = tmp % 10;
                break;
            }
            tmp /= 10;
        }
        ++num[top][bottom];
    }
    rep(i, 10) rep(j, 10) {
        ans += num[i][j] * num[j][i];
    }
    cout << ans << endl;
    return 0;
}