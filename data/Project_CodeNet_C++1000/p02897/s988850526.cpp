#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    double N, cnt = 0; cin >> N;
    for (int i = 1; i <= N; ++i) if (i % 2 != 0) cnt++;
    printf("%f\n", cnt / N);
}