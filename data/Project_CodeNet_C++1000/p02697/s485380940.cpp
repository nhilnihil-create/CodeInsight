#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <bitset>
#include <random>
#include <stack>
#include <deque>
typedef long long LL;
using namespace std;
typedef std::pair<int, int> pii;
typedef std::pair<LL, LL> pll;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    if (N % 2) {
        for (int i = 0; i < M; i++) {
            printf("%d %d\n", i + 1, N - i);
        }
     } else {
        int hf = (N - 1) / 2;
        for (int i = 0; i < min(hf, M); i++) {
            int a = hf - i, b = hf + i + 1;
            if (i * 2 >= hf) b++;
            printf("%d %d\n", a, b);
        }
    }
    return 0;
}
