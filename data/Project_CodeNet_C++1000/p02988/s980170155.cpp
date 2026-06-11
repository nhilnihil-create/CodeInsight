#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int my_mid(int x, int y, int z) {
    if ((x > y && x < z) || (x < y && x > z)) {
        return x;
    }
    else if ((y > x && y < z) || (y < x && y > z)) {
        return y;
    }
    else if ((z > x && z < y) || (z < x && z > y)) {
        return z;
    }
    else
    {
        return 0;
    }
}
int main() {
    int N; cin >> N;
    vector<int> P(N, 0);
    for (int i = 0; i < N; ++i) cin >> P[i];
    int cnt = 0;
    for (int i = 1; i < N - 1; ++i) if (my_mid(P[i - 1], P[i], P[i + 1]) == P[i]) cnt++;
    printf("%d\n", cnt);
}
