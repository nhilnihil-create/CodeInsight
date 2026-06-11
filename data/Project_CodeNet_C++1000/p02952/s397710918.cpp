#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int digit_ret(int x) {
    int digit_cnt = 0;
    while(x > 0) {
        x /= 10;
        digit_cnt++;
    }
    return digit_cnt;
}
int main() {
    int N; cin >> N;
    int count = 0;
    for (int i = N; i >= 1 ; --i) {
        if (digit_ret(i) % 2 != 0) count++;
    }
    printf("%d\n", count);
}
