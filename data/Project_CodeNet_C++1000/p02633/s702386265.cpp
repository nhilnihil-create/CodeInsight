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
    int x;
    cin >> x;
    int num[180] = {0};
    int tmp_x = x;
    for (int i = 2; i * i <= x; ++i) {
        while(1) {
            if (tmp_x % i != 0) break;
            tmp_x /= i;
            ++num[i];
        }
    }
    if (tmp_x != 1) ++num[tmp_x];
    int tmp_num = 360;
    int mult_num = 1;
    rep(i, 180) {
        if (num[i] != 0) {
            rep(j, num[i]) {
                if (tmp_num % i != 0) {
                    mult_num *= i;
                }
                else {
                    tmp_num /= i;
                }
            }
        }
    }
    cout << 360 * mult_num / x << endl;
    return 0;
}
