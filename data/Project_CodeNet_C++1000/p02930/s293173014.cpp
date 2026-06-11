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
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int ans = 0, tmp = (i ^ j);
            while (tmp) {
                  ans++;
                  tmp >>= 1;
            }
            printf("%d ", ans);
        }
        puts("");
    }
    return 0;
}
