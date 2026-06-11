#include <iostream>
using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int main() {

    int n;
    cin >> n;
    int p[101] = {0};
    for (int i = 1; i <= n; ++i) {
        cin >> p[i - 1] >> p[i];
    }

    int m[101][101] = {0};
    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            m[i][j] = (1 << 21);
            for (int k = i; k <= j - 1; ++k) {
                m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
            }
        }
    }

    cout << m[1][n] << endl;
    return 0;
}