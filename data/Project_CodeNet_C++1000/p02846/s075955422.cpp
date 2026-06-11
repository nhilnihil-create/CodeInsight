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
LL A[2], B[2];

void INF() {
     puts("infinity");
     exit(0);
}

void NO() {
     puts("0");
     exit(0);
}

int main() {
    int T1, T2;
    scanf("%d %d", &T1, &T2);
    scanf("%lld %lld", &A[0], &A[1]);
    scanf("%lld %lld", &B[0], &B[1]);
    if (A[0] < B[0]) {
       swap(A[0], B[0]);
       swap(A[1], B[1]);
    }
    if (A[0] == B[0]) INF();
    // A0 > B0
    LL tmp = (A[0] - B[0]) * T1 + (A[1] - B[1]) * T2;
    if (!tmp) INF();
    if (tmp > 0) NO();
    tmp *= -1;
    LL cnt = (A[0] - B[0]) * T1;
    LL ans = 0;
    if (cnt % tmp) ans++;
    printf("%lld\n", ans + (cnt / tmp) * 2);


    return 0;
}
