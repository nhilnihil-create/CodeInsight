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

int main(){
    int m, d;
    cin >> m >> d;
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= d; ++j) {
            if (j%10 < 2 || j/10 < 2) continue;
            if ((j%10) * (j/10) == i) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
}
