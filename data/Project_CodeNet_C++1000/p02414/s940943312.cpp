#include <iostream>
using namespace std;

int main() {
    int n, m, l;
    int a[100][100], b[100][100];
    long long int c[100][100];

    for (int i = 0; i < 100; i++) {
        for (int h = 0; h < 100; h++) {
            a[i][h] = 0;
            b[i][h] = 0;
            c[i][h] = 0;
        }
    }

    cin >> n >> m >> l;

    for (int i = 0; i < n; i++) {
        for (int h = 0; h < m; h++) {
            cin >> a[i][h];
        }
    }


    for (int i = 0; i < m; i++) {
        for (int h = 0; h < l; h++) {
            cin >> b[i][h];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int h = 0; h < l; h++) {
            for (int s = 0; s < m; s++) {
                c[i][h] += a[i][s] * b[s][h];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int h = 0; h < l; h++) {
            cout << c[i][h];
            if (h != (l - 1)) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }
}