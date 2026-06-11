#include <iostream>
using namespace std;

int main() {
    int X, R, N, K, res;
    cin >> X;
    N = X / 100;
    R = X % 100;
    K = R / 5;
    if (R % 5 > 0) {
        K++;
    }

    res = K <= N ? 1 : 0;

    cout << res << endl;
    return 0;
}

