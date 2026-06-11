#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int M, D; cin >> M >> D;
    int cnt = 0;
    for (int i = 4; i <= M; i++) {
        for (int j = 22; j <= D; j++) {
            if ((j / 10) * (j % 10) == i && j / 10 >= 2 && j % 10 >= 2) cnt++;
        }
    }
    printf("%d\n", cnt);
}
