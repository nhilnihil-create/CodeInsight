#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, L, sum = 0; cin >> N >> L;
    for (int i = 1; i <= N; ++i) sum += L + i - 1;
    int tmp = 10e9 + 1, ans = 0;
    for (int i = 1; i <= N; ++i) {
        int x = sum - (L + i - 1);
        if (tmp >= abs(sum - x)) tmp = abs(sum - x), ans = i;
    }
    sum = 0;
    for (int i = 1; i <= N; ++i) {
        if (ans == i) continue;
        sum += L + i - 1;
    }
    printf("%d\n", sum);
}
