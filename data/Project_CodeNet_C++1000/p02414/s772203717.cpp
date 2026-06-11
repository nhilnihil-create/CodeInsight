#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    int matrix1[n][m] = {};
    int matrix2[m][p] = {};
    double matrix3[n][p] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix1[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cin >> matrix2[i][j];
        }
    }
    int sum = 0;

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            for (int j = 0; j < p; j++) {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    cout << fixed << setprecision(0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            if (j == p - 1) {
                cout << matrix3[i][j] << endl;
            } else {
                cout << matrix3[i][j] << " ";
            }
        }
    }
    return 0;
}
