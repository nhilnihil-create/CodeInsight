#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;


int main()
{
    int n, t;
    cin >> n;
    int x[n];
    int y[n];
    double total = 0, root, max = 0;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
        if (abs(x[i] - y[i]) > max) max = abs(x[i] - y[i]);
    }

    for (int j = 1; j < 4; j++){
        for (int i = 0; i < n; i++) {
            total += pow(abs(x[i] - y[i]), j);
        }
        root = 1.0 / j;
        printf("%.10f\n", pow(total, root));
        total = 0;
    }
    printf("%.10f\n", max);
    return 0;
}