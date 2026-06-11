#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <unordered_map>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

int main() {
    int M;
    scanf("%d", &M);
    LL sum = 0, ans = 0;
    for (int i = 0; i < M; i++) {
        LL d, c;
        scanf("%lld %lld", &d, &c);
        sum += (d * c);
        ans += c;
    }
    ans--;
    while (sum >= 10) {
          LL tmp = sum / 10;
          ans += (tmp);
          sum %= 10;
          sum += tmp;
    }
    printf("%lld\n", ans);

    return 0;
}
