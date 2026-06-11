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

int main() {
    int n;
    int data[1000] = {0};
    double avg, total;
    while (1) {
        cin >> n;
        if (n == 0) break;
        total = 0;
        for (int i = 0; i < n; i++) {
            cin >> data[i];
            total += data[i];
        }
        avg = total / n * 1.0;
        total = 0;
        for (int j = 0; j < n; j++) {
            total += pow(data[j] - avg, 2.0) / n * 1.0;
        }
        printf("%.10f\n", sqrt(total));
    }
    return 0;
}