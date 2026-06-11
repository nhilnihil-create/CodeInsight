#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main() {

    int n;                  // XとYの次元数n
    int x[100];             // ベクトル
    int y[100];             // ベクトル

    double S[4] = {0};
    double D[4];  // ミンコフスキー距離

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    for (double p = 0; p < 3; p++) {

        for (int i = 0; i < n; i++) {
            S[(int)p] += pow(abs(x[i] - y[i]), p + 1);
        }

        D[(int)p] = pow(S[(int)p], 1 / (p + 1));

    }

    D[3] = x[0] - y[0];

    for (int i = 0; i < n; i++) {
        if (abs(x[i] - y[i]) > D[3]) {
            D[3] = abs(x[i] - y [i]);
        }
    }

    cout << fixed;

    for (int i = 0; i < 4; i++) {
        cout << setprecision(10) << D[i] << endl;
    }

    return 0;
}
