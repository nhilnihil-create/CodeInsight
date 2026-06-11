#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> W(N, 0);
    for (int i = 0; i < N; ++i) cin >> W[i];
    int a = 0, b = 0, i = 0, j = N - 1;
    while (i <= j) {
        if (a <= b) {
            a += W[i], i++;
        }
        else {
            b += W[j], j--;
        }
    }
    printf("%d\n", abs(a - b));
}
