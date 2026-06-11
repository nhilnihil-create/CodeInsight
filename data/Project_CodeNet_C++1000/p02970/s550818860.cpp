#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, D; cin >> N >> D;
    int cnt = 0;
    int tmp = 2 * D + 1;
    while(N > 0) {
        N -= tmp;
        cnt++;
    }
    printf("%d\n", cnt);
}
