#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>


using namespace std;

double minkowsky1(int n, int *x, int *y);
double minkowsky2(int n, int *x, int *y);
double minkowsky3(int n, int *x, int *y);
double chebyshev(int n, int *x, int *y);

int main() {
    cout << fixed;
    cout << setprecision(10);

    int n;
    cin >> n;

    int x[n];
    memset(x, 0, sizeof(int) * n);
    int y[n];
    memset(y, 0, sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    cout << minkowsky1(n,x,y) << endl;
    cout << minkowsky2(n,x,y) << endl;
    cout << minkowsky3(n,x,y) << endl;
    cout << chebyshev(n,x,y) << endl;

    return 0;
}

double minkowsky1(int n, int *x, int *y) {
    double ret = 0;
    for (int i = 0; i < n; i++) {
        ret += abs(x[i] - y[i]);
    }
    return ret;
}

double minkowsky2(int n, int *x, int *y) {
    double ret = 0;
    for (int i = 0; i < n; i++) {
        ret += pow(x[i] - y[i], 2);
    }
    return sqrt(ret);
}

double minkowsky3(int n, int *x, int *y) {
    double ret = 0;
    for (int i = 0; i < n; i++) {
        ret += pow(abs(x[i] - y[i]), 3);
    }
    return cbrt(ret);
}

double chebyshev(int n, int *x, int *y) {
    double ret = 0;
    for (int i = 0; i < n; i++) {
        int tmp = abs(x[i] - y[i]);

        if (tmp > ret)
            ret = tmp;
    }
    return ret;
}