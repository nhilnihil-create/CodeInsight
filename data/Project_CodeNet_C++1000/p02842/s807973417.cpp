#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    double N; cin >> N;
    for (int i = 1; i <= 500000; ++i) {
        int x = i * 1.08;
        if (N == x) {
            printf("%d\n", i); return 0;
        }
    }
    printf("%s\n", ":(");
    return 0;
}
