#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, K, cnt = 0; cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        if (a >= K) cnt++;
    }
    printf("%d\n", cnt);
}
