#include <iostream>
using namespace std;

int main() {
    int max = 100;
    int n;
    cin >> n; // take the input
    int p[max + 1], m[max + 1][max + 1];
    for (int i = 1; i <= n; i++) {
        cin >> p[i - 1] >> p[i]; // scan in the matrix
    }

    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
        for (int t = 2; t <= n; t++) {
            for (int i = 1; i <= n - t + 1; i++) {
                int j = i + t - 1;
                m[i][j] = (1 << 21);
                for (int k = i; k <= j - 1; k++) {
                    m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
                }
            }
        }
    }

    cout << m[1][n] << endl;
    return 0;
}
